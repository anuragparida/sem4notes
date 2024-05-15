figure(2);
plot(e);
ind_s=25000;
ind_e=32000;

plot(Omega(ind_s:ind_e),e(ind_s:ind_e));
xlabel('Angular velocity\omega(rad/s)');
ylabel('Induced emf e_M (V)');
