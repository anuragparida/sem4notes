function case_1 ( )
%−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
% 1. Constant definitions
%
T_A = 0.01; % Armature time constant
T_f = 0.2; % Excitation time constant
T_J = 0.8; % Ramp−up time
T_abt = 0.002; % Sampling time
tau_A = T_A/T_abt; tau_f = T_f/T_abt; tau_J=T_J/T_abt;
r_A =0.04; % Relative armature resistor (r_A = R_A / (U_AN/ I_AN ) )
r_f =1; % Relative field excitation resistor (r_f = R_f / ( U_fN / I_fN ) )
k_max=2/T_abt;
%−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
% 2. Input values / equations
%
k_on = 0.5/T_abt;
for k = 1:k_on+1
u_A(k) = 1;
m_L(k) = 0.05;
u_f(k) = 1-(k-1)/k_on*0.5 ;
end

for k = k_on+1:k_max+1
u_A(k) = 1;
m_L(k) = 0.05;
u_f(k) = 0.5;
end

%−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
% 3. Start values
%
i_A(1) = 0; Phi_f(1) = 1; Om(1) = 1;
i_f(1) = 1; m_i(1) = i_A(1)*Phi_f(1);

%−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
% 4 . / 5 . Calculation
%
for k=1:k_max
i_A(k+1) = (1-1/tau_A )* i_A(k)+(u_A(k)-Om(k)*Phi_f(k))/tau_A/r_A ;
Phi_f(k+1) = Phi_f(k)+(u_f(k)/r_f-i_f(k))/tau_f;
i_f(k+1) = Phi_f(k+1);
m_i(k+1) = Phi_f(k+1)*i_A(k+1);
Om(k+1) = Om(k)+(m_i (k)-m_L(k))/tau_J;
end

%−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
% 6. Graphical output
%
zeit = linspace(0, 2, k_max+1);
plot(zeit,Om,'b',zeit,u_f,'r:',zeit,i_f,'r--',zeit,i_A,'b:',zeit,m_i,'g--');
grid on;
xlabel("Time [s]");
ylabel("x = X/X_n [p.u.]");
legend("\Omega_m","u_f", "i_f","i_A","m_i");
print(gcf,'fall_1.png','-dpng','-r300');  
