
function [sys,x0,str,ts] = reference_trajectory1(t,x,u,flag)
switch flag
case 0
 [sys,x0,str,ts]=mdlInitializeSizes;
case 1
 sys=mdlDerivatives(t,x,u);
case 3
 sys=mdlOutputs(t,x,u);
case {2,4,9}
 sys=[];
otherwise
 error(['Unhandled flag = ',num2str(flag)]);
end
function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates= 0;
sizes.NumDiscStates= 0;
sizes.NumOutputs= 3;%环境位置\一阶导数\二阶导数
sizes.NumInputs= 0;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys = simsizes(sizes);
x0= [];
str = [];
ts= [0 0];

function sys=mdlOutputs(t,x,u)
xe=0.1;%参考位置%
dxe=0;%参考速度%
ddxe=0;%参考加速度%
sys(1)=xe;
sys(2)=dxe;
sys(3)=ddxe;


