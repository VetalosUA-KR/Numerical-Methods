clear;
m=input('PODAJ LICZB� W�Z��W (0 - QUIT) m=');
if (m==0) end
if (m<0) || (m==1)  || (m==2) abs3; end
if (m>2)
n=m-1;
a=-1;b=1;
step1=(b-a)/n;
x=a:step1:b;
y=abs(5*x);
for i=0:n
   xc(i+1)=cos((2*i+1)*pi/(2*n+2));
end;
yc=abs(5*xc);
step2=(b-a)/100;
xt=a:step2:b;
wnc=polyfit(xc,yc,n);
ywnc=polyval(wnc,xt);
ysp=spline(x,y,xt);

plot(x,y,'ko',xt,abs(5*xt),'y-',xt,ywnc,'r-',xt,ysp,'g-');
legend('wezly rownoodlegle','funkcja interpolowana','wielomian Czebyszewa','splajny');
abs3;
end