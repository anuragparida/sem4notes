figure(3);
subplot(2,1,1);
plot(t(1:15000),Omega(1:15000));
xlabel('Time (s)')
ylabel('\Omega (rad/s)')
subplot(2,1,2);
plot(t(1:15000),i(1:15000));
xlabel('Time (s)')
ylabel('i_A (A)')