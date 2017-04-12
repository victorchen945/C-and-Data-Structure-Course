/* 1250300 建筑 陈正阳 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/* 不允许对本函数做任何修改
   除本函数外，不允许任何函数中输出“零”-“玖”!!!!!! */

char result[256];
char chistr[]="零壹贰叁肆伍陆柒捌玖";
char chistr2[]="拾佰仟万亿圆角分整";

void daxie(int num, int flag_of_zero, int counter)
{
	switch(num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				result[counter]=chistr[0];
				result[counter+1]=chistr[1];
			break;
		case 1:
			result[counter]=chistr[2];
			result[counter+1]=chistr[3];
			break;
		case 2:
			result[counter]=chistr[4];
            result[counter+1]=chistr[5];
			break;
		case 3:
			result[counter]=chistr[6];
            result[counter+1]=chistr[7];
			break;
		case 4:
			result[counter]=chistr[8];
            result[counter+1]=chistr[9];
			break;
		case 5:
			result[counter]=chistr[10];
            result[counter+1]=chistr[11];
			break;
		case 6:
			result[counter]=chistr[12];
            result[counter+1]=chistr[13];
			break;
		case 7:
			result[counter]=chistr[14];
            result[counter+1]=chistr[15];
			break;
		case 8:
			result[counter]=chistr[16];
            result[counter+1]=chistr[17];
			break;
		case 9:
			result[counter]=chistr[18];
            result[counter+1]=chistr[19];
			break;
		default:
			cout << "error";
			break;
		}
}

/* 可根据需要自定义其它函数 */

/*test*/
/*int main()
{
    //int flag_of_zero=0;
    double a;
	int test(double);
	test(9999999999.99);
	cout<<endl;
	test(9999999999.90);
	cout<<endl;
	test(9999999999.09);
	cout<<endl;
	test(9900000000);
	cout<<endl;
	test(8912003005.78);
	cout<<endl;
	test(2501200350.03);
	cout<<endl;
	test(1203056740.01);
	cout<<endl;

}
*/

/* 根据需要完成main函数 */
//int test(double a)
int main()
{
    int flag_of_zero=0;
    static int counter=0;
    double a;
	double y;
	int tb = 0, b = 0, hm = 0, tm = 0, m = 0, ht = 0, tt = 0, t = 0, h = 0, d = 0, yuan = 0,mao = 0, cen = 0;
	cout << "please enter the complex number: " << endl;
	cin >> a;
	y = (((a + 0.0001) / 1000) - (int)(a / 1000)) * 1000;
	//cout << setiosflags(ios::fixed) << setprecision(2) << y << endl;
	tb = (int)(a / 10000000000);
	b = (int)(a / 1000000000) % 10;
	hm = (int)(a / 100000000) % 10;
	tm = (int)(a / 10000000) % 10;
	m = (int)(a / 1000000) % 10;
	ht = (int)(a / 100000) % 10;
	tt = (int)(a / 10000) % 10;
	t = (int)(a / 1000) % 10;
	h = (int)(a / 100) % 10;
	d = (int)(a / 10) % 10;
	yuan = (int)(y / 1) % 10;
	mao = (int)(y / 0.1) % 10;
	cen = (int)(y / 0.01) % 10;

	if (tb||b||hm)
	{
		daxie(tb,flag_of_zero,counter);
		counter+=2;
		if (tb)
            {
                result[counter]=chistr2[2];
                result[counter+1]=chistr2[3];
                counter+=2;
            }
		if (tb&&hm)
            flag_of_zero=1;
		daxie(b,flag_of_zero,counter);
		counter+=2;
		if (b)
            {
                result[counter]=chistr2[0];
                result[counter+1]=chistr2[1];
                counter+=2;
            }
		flag_of_zero=0;
		daxie(hm,flag_of_zero,counter);
		counter+=2;
        result[counter]=chistr2[8];
        result[counter+1]=chistr2[9];
        counter+=2;
        if (!tm && (m || ht || tt || t || h || d || yuan))
		{
			if (!(m||ht||tt))
				flag_of_zero=0;
			else
				flag_of_zero=1;
		}

		else
			flag_of_zero=0;


	}
	if (tm || m || ht || tt)
	{
		daxie(tm,flag_of_zero,counter);
		counter+=2;
		if (tm)
            {
                result[counter]=chistr2[4];
                result[counter+1]=chistr2[5];
                counter+=2;
            }
		if (tm && (ht || tt))
				flag_of_zero=1;
		daxie(m,flag_of_zero,counter);
		counter+=2;
		if (m)
            //cout<<"佰";
            {
                result[counter]=chistr2[2];
                result[counter+1]=chistr2[3];
                counter+=2;
            }
		if (m&&tt)
				flag_of_zero=1;
		daxie(ht,flag_of_zero,counter);
		counter+=2;
		if(ht)
            //cout<<"拾";
        {
            result[counter]=chistr2[0];
            result[counter+1]=chistr2[1];
            counter+=2;
        }
		flag_of_zero=0;
		daxie(tt,flag_of_zero,counter);
		counter+=2;
		//cout<<"万";
		result[counter]=chistr2[6];
        result[counter+1]=chistr2[7];
        counter+=2;

		if (!t && ( h || d||yuan))
			flag_of_zero=1;
	}
	if (t || h || d || yuan)
	{
		daxie(t,flag_of_zero,counter);
		counter+=2;
		if (t)
           // cout<<"仟";
        {
            result[counter]=chistr2[4];
            result[counter+1]=chistr2[5];
            counter+=2;
        }
		if (t && !h&&(d || yuan))
				flag_of_zero=1;
		daxie(h,flag_of_zero,counter);
		counter+=2;
		if (h&&yuan&&!d)
        {
            if(flag_of_zero)
				flag_of_zero=0;
            else flag_of_zero=1;
        }
		if (h)
        {
            result[counter]=chistr2[2];
            result[counter+1]=chistr2[3];
            counter+=2;
        }
		daxie(d,flag_of_zero,counter);
		counter+=2;
		if (d)
        //    cout<<"拾";
        {
            result[counter]=chistr2[0];
            result[counter+1]=chistr2[1];
            counter+=2;
        }
		flag_of_zero=0;
		daxie(yuan,flag_of_zero,counter);
		counter+=2;

	}
	if (tb || b || hm || tm || m || ht || tt || t || h || d || yuan)
	{
		if (!mao&&!cen)
			//cout << "圆整";
        {
            result[counter]=chistr2[10];
            result[counter+1]=chistr2[11];
            result[counter+2]=chistr2[16];
            result[counter+3]=chistr2[17];
            counter+=4;
        }
		else
        {
            result[counter]=chistr2[10];
            result[counter+1]=chistr2[11];
            counter+=2;
        }
	}
	flag_of_zero=0;

	if (mao || cen)
	{
	    if (cen&&(tb || b || hm || tm || m || ht || tt || t || h || d || yuan))
			flag_of_zero=1;
		daxie(mao,flag_of_zero,counter);
		counter+=2;
		flag_of_zero=0;
		if (mao)
		{
			if (!cen)
				//cout << "角整";
            {
                result[counter]=chistr2[12];
                result[counter+1]=chistr2[13];
                result[counter+2]=chistr2[16];
                result[counter+3]=chistr2[17];
                counter+=4;
            }
			else
				//cout << "角";
            {
                result[counter]=chistr2[12];
                result[counter+1]=chistr2[13];
                counter+=2;
            }
		}
		flag_of_zero=0;

		daxie(cen,flag_of_zero,counter);
		counter+=2;
		if (cen)
        {
            result[counter]=chistr2[14];
            result[counter+1]=chistr2[15];
            counter+=2;
        }
	}
	if (!(tb || b || hm || tm || m || ht || tt || t || h || d || yuan || cen || mao))
    {
        flag_of_zero=1;
        daxie(yuan,flag_of_zero,counter);
		counter+=2;
        result[counter]=chistr2[10];
        result[counter+1]=chistr2[11];
        result[counter+2]=chistr2[16];
        result[counter+3]=chistr2[17];
        counter+=4;
    }
    cout<<result<<endl;

	return 0;
}
