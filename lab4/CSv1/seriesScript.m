t = PIDCon.time;
u = PIDCon.signals(1).values(:,1);
y1 = PCon.signals(1).values(:,2);
y2 = PICon.signals(1).values(:,2);
y3 = PIDCon.signals(1).values(:,2);

plot(t,u,t,y1,t,y2,t,y3);
xlabel('Time/s');
ylabel('Signals/V');
legend({'w','yP', 'yPI', 'yPID'});
title('Validation of Series');

%{
u1 = PCon.signals(2).values(:,1);
u2 = PICon.signals(2).values(:,1);
u3 = PIDCon.signals(2).values(:,1);
plot(t,u1,t,u2,t,u3);
xlabel('Time/s');
ylabel('Signals/V');
legend({'uP', 'uPI', 'uPID'});
title('Validation of Series');
%}