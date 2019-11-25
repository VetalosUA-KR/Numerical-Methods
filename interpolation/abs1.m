clear;
m=input('PODAJ LICZBÊ WÊZ£ÓW (0 - QUIT) m=');
if (m==0) end
if (m<0) || (m==1) abs1; end
if (m>1)
n=m-1;
a=-1;b=1;
step1=(b-a)/n;
x=a:step1:b;
y=abs(5*x);
step2=(b-a)/100;
xt=a:step2:b;
wn=polyfit(x,y,n);
ywn=polyval(wn,xt);
plot(x,y,'ko',xt,abs(5*xt),'y-',xt,ywn,'b-');
legend('wezly rownoodlegle','funkcja interpolowana','wielomian Lagrange-a');
abs1;
end