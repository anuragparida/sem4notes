stairs(t,u);
hold on;
plot(t, i);
hold off;

grid on;
xlim([2.995 3.04]);
ylim([-0.1 5.1]);

xlabel('Time(sec)')
legend({'u_A/V', 'i_A/A'})