function case_2 ( )
%−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
% 1. Constant definitions
%
T_A = 0.01; % Armature time constant
T_f = 0.2; % Excitation time constant
T_J = 0.8; % Ramp−up time
T_abt = 0.001; % Sampling time
tau_A = T_A/T_abt; tau_f = T_f/T_abt; tau_J=T_J/T_abt;
r_A =0.04; % Relative armature resistor (r_A = R_A / (U_AN/ I_AN ) )
r_f =1; % Relative field excitation resistor (r_f = R_f / ( U_fN / I_fN ) )
k_max=1.5/T_abt;
K_R_om=20; T_R_om=0.1; % Parameter speed controller
q0_om =K_R_om; q1_om=K_R_om*(T_abt/T_R_om -1);
K_R_A=0.5; T_R_A=0.01; % Parameter armature current controller
q0_A =K_R_A; q1_A=K_R_A*(T_abt/T_R_A -1);
K_R_f=1;   T_R_f=0.05; % Parameter field current controller
q0_f =K_R_f; q1_f=K_R_f*(T_abt/T_R_f -1);
%−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
% 2. Input values / equations
%
for k=1:k_max+1
    Om_soll(k)=2;
    m_L(k)=0.1;
end

%−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
% 3. Start values
%
i_A(1)=0;Phi_f(1)=1;Om(1)=0;
i_f(1)=1;m_i(1)=i_A(1)*Phi_f(1);
i_ASoll(1)=0;u_A(1)=0;u_f(1)=1;i_fSoll(1)=1;
e_om(1)=0;e_A(1)=0;e_f(1)=0;

for k=1:k_max
    %---------------------------------------------------------------------
    % 4. Calculate DC motor
    %
    i_A(k+1)  =(1-1/tau_A)*i_A(k)+(u_A(k)-Om(k)*Phi_f(k))/tau_A/r_A;
    Phi_f(k+1)=Phi_f(k)+(u_f(k)/r_f-i_f(k))/tau_f;
    i_f(k+1)  =Phi_f(k+1);
    m_i(k+1)  =Phi_f(k+1)*i_A(k+1);
    Om(k+1)   =Om(k)+(m_i(k)-m_L(k))/tau_J;
    %---------------------------------------------------------------------
    % 5. Calculate controller + set value limits
    %
    e_om(k+1)=Om_soll(k+1)-Om(k+1);
    i_ASoll(k+1)=i_ASoll(k)+q0_om*e_om(k+1)+q1_om*e_om(k);
    i_ASoll(k+1)=local_limit(i_ASoll(k+1),2.0);
    e_A(k+1)=i_ASoll(k+1)-i_A(k+1);
    u_A(k+1)=u_A(k)+q0_A*e_A(k+1)+q1_A*e_A(k);
    u_A(k+1)=local_limit(u_A(k+1),1.2);
    if abs(Om(k+1)) > 1
        i_fSoll(k+1)=1/abs(Om(k+1));
    else
        i_fSoll(k+1)=1;
    end
    e_f(k+1)=i_fSoll(k+1)-i_f(k+1);
    u_f(k+1)=u_f(k)+q0_f*e_f(k+1)+q1_f*e_f(k);
    u_f(k+1)=local_limit(u_f(k+1),1.0);
end
zeit=linspace(0,1.5,k_max+1);
% plot(zeit,Om,zeit,u_f,zeit,i_f,zeit,i_A,zeit,m_i)
plot(zeit,i_A,'b:',zeit,Om,'b',zeit,u_A,'g:',zeit,m_i,'g--',...
     zeit,i_f,'r--',zeit,u_f,'r-.');
xlabel("Time [s]")
ylabel("x = X/X_n [p.u.]")
legend("i_A", "\Omega_m","u_A", "m_i","i_f","u_f")
grid on
print(gcf,'case_2.png','-dpng','-r300');  

%-------------------------------------------------------------------------
% Limits of the set point values as local function
%
function back = local_limit(val,lim)
if val > lim
    back = lim;
elseif val < -lim
    back = -lim;
else
    back = val;
end
return