t = GS3.time;
u = GS3.signals(1).values(:,1);
y = GS3.signals(1).values(:,2);


K = 1.49;
T = 0.5;
G = tf(K, [T 1]);

ym = lsim(G, u, t);

plot(t,u,t,y,t,ym);
xlabel('Time/s');
ylabel('Signals/V');
legend({'u','y', 'y_M'});
title('Validation of System 1');