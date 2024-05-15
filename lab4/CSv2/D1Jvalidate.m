%J = 0.00551453;
J = 0.0056;
tau_F0 = 0.03978;
alpha_F = 0.0002377;
tC=t(ind_s:ind_e);
wC=Omega(ind_s:ind_e);
wSim=zeros(size(wC));
dT=0.001;
wSim(1)=wC(1);

for k=1:length(wC)-1
    Tf=tau_F0 + alpha_F*wSim(k);
    wSim(k+1)=wSim(k)-dT*Tf/J;
end

plot(tC,wC,'b',tC,wSim,'k');
xlabel('Time (s)')
ylabel('Angular velocity\omega(rad/s)')
legend({'Measured','Simulated'})
title('Validation of moment of inertia J')