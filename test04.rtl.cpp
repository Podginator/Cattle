#include <fstream>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <string>
using namespace std;
float retOneNum()
{
float _0retOneNumret;
_0retOneNumret = 1;

return _0retOneNumret;
}
std::tuple<float,float,float> retThreeNum()
{
float _0retThreeNumret;
_0retThreeNumret = 2;
float _1retThreeNumret;
_1retThreeNumret = 3;
float _2retThreeNumret;
_2retThreeNumret = 4;

return std::make_tuple(_0retThreeNumret,_1retThreeNumret,_2retThreeNumret);
}
std::tuple<float,float> retTwoNum()
{
float _0retTwoNumret;
_0retTwoNumret = 5;
float _1retTwoNumret;
_1retTwoNumret = 6;

return std::make_tuple(_0retTwoNumret,_1retTwoNumret);
}
std::tuple<float,float,float,float,float,float> expectFiveParam(float a,float b,float c,float d,float e,float f)
{
float _0expectFiveParamret;
_0expectFiveParamret = a;
float _1expectFiveParamret;
_1expectFiveParamret = b;
float _2expectFiveParamret;
_2expectFiveParamret = c;
float _3expectFiveParamret;
_3expectFiveParamret = d;
float _4expectFiveParamret;
_4expectFiveParamret = e;
float _5expectFiveParamret;
_5expectFiveParamret = f;

return std::make_tuple(_0expectFiveParamret,_1expectFiveParamret,_2expectFiveParamret,_3expectFiveParamret,_4expectFiveParamret,_5expectFiveParamret);
}
std::tuple<float,float,float,float,float,float> param_tuple;
float g;
float h;
float i;
float j;
float k;

// Main 
int main(int argc, char **argv) 
{

{
float __0tuple_assign;

{
float __0retOneNum;

__0retOneNum=retOneNum();
__0tuple_assign = __0retOneNum;

}
float __1tuple_assign;
float __2tuple_assign;
float __3tuple_assign;

{
std::tuple<float,float,float> __0retThreeNum;

__0retThreeNum=retThreeNum();
__1tuple_assign = std::get<0>(__0retThreeNum);
__2tuple_assign = std::get<1>(__0retThreeNum);
__3tuple_assign = std::get<2>(__0retThreeNum);

}
float __4tuple_assign;
float __5tuple_assign;

{
std::tuple<float,float> __0retTwoNum;

__0retTwoNum=retTwoNum();
__4tuple_assign = std::get<0>(__0retTwoNum);
__5tuple_assign = std::get<1>(__0retTwoNum);

}
param_tuple = std::make_tuple(__0tuple_assign,__1tuple_assign,__2tuple_assign,__3tuple_assign,__4tuple_assign,__5tuple_assign);
}
;

{
std::tuple<float,float,float,float,float,float> __0expectFiveParam;
float __0expectFiveParamparam0;
float __0expectFiveParamparam1;
float __0expectFiveParamparam2;
float __0expectFiveParamparam3;
float __0expectFiveParamparam4;
float __0expectFiveParamparam5;
__0expectFiveParamparam0 = std::get<0>(param_tuple);
__0expectFiveParamparam1 = std::get<1>(param_tuple);
__0expectFiveParamparam2 = std::get<2>(param_tuple);
__0expectFiveParamparam3 = std::get<3>(param_tuple);
__0expectFiveParamparam4 = std::get<4>(param_tuple);
__0expectFiveParamparam5 = std::get<5>(param_tuple);
__0expectFiveParam=expectFiveParam(__0expectFiveParamparam0,__0expectFiveParamparam1,__0expectFiveParamparam2,__0expectFiveParamparam3,__0expectFiveParamparam4,__0expectFiveParamparam5);
g = std::get<0>(__0expectFiveParam);
h = std::get<1>(__0expectFiveParam);
i = std::get<2>(__0expectFiveParam);
j = std::get<3>(__0expectFiveParam);
k = std::get<4>(__0expectFiveParam);

}

{
float __0print;
__0print = g;
cout << __0print<< endl;
}

{
float __1print;
__1print = h;
cout << __1print<< endl;
}

{
float __2print;
__2print = i;
cout << __2print<< endl;
}

{
float __3print;
__3print = j;
cout << __3print<< endl;
}

{
float __4print;
__4print = k;
cout << __4print<< endl;
}

}
