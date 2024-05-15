t = GS2.time;
u = GS2.signals(1).values(:,1);
y = GS2.signals(1).values(:,2);


K = 0.765;
Omega0 = 4.9;
D = 0.38 ;
G = tf(K, [1/Omega0^2 2*D/Omega0 1]);

ym = lsim(G, u, t);

plot(t,u,t,y,t,ym);
xlabel('Time/s');
ylabel('Signals/V');
legend({'u','y', 'y_M'});
title('Validation of Series');