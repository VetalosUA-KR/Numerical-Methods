clear;
m=input('PODAJ LICZB� W�Z��W (0 - QUIT) m=');
if (m==0) end
if (m<0) || (m==1) rat1; end
if (m>1)
n=m-1;
a=-1;b=1;
step1=(b-a)/n;
x=a:step1:b;
y=1./(1+100.*x.*x);
step2=(b-a)/100;
xt=a:step2:b;
wn=polyfit(x,y,n);
ywn=polyval(wn,xt);
plot(x,y,'ko',xt,1./(1+100.*xt.*xt),'y-',xt,ywn,'b-');
legend('wezly rownoodlegle','funkcja interpolowana','wielomian Lagrange-a');
rat1;
end