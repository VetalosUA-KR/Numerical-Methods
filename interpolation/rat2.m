clear;
m=input('PODAJ LICZBÊ WÊZ£ÓW (0 - QUIT) m=');
if (m==0) end
if (m<0) || (m==1) rat2; end
if (m>1)
n=m-1;
a=-1;b=1;
step1=(b-a)/n;
x=a:step1:b;
y=1./(1+100.*x.*x);
for i=0:n
   xc(i+1)=cos((2*i+1)*pi/(2*n+2));
end;
yc=1./(1+100.*xc.*xc);
step2=(b-a)/100;
xt=a:step2:b;
wn=polyfit(x,y,n);
wnc=polyfit(xc,yc,n);
ywn=polyval(wn,xt);
ywnc=polyval(wnc,xt);

plot(x,y,'ko',xc,yc,'g*',xt,1./(1+100.*xt.*xt),'y-',xt,ywn,'b-',xt,ywnc,'r-');
legend('wezly rownoodlegle','wezly Czebyszewa','funkcja interpolowana','wielomian Lagrange-a','wielomian Czebyszewa');
rat2;
end