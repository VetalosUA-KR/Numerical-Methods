clear;
m=input('PODAJ LICZB� W�Z��W (0 - QUIT) m=');
if (m==0) end
if (m<0) || (m==1) abs1p; end
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
err=abs(ywn-abs(5*xt));
bar(xt,err);
abs1p;
end