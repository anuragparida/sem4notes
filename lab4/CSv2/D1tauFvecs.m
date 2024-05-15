kG = 0.1263;

Omega1=mean(Omega(5850:5950));
Omega2=mean(Omega(8850:8950));
Omega3=mean(Omega(11850:11950));
Omega4=mean(Omega(14850:14950));

i1=mean(i(5850:5950));
i2=mean(i(8850:8950));
i3=mean(i(11850:11950));
i4=mean(i(14850:14950));

%VecOmega = [34.6114, 74.0805, 114.1338, 154.3996];
%VecTau = [0.3652, 0.4636, 0.5369, 0.5935]*kG;

VecOmega = [Omega1, Omega2, Omega3, Omega4];
VecTau = [i1, i2, i3, i4]*kG;

figure(4);
plot(VecOmega, VecTau);
xlabel('\omega (rad/s)')
ylabel('\tau_F (Nm)')