// API.cpp : 定义控制台应用程序的入口点。
//



#include "okexapi.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
    string com_apiKey		= "";//请到www.okex.com申请。
    string com_secretKey	= "";//请到www.okex.com申请。
    OkexApiCom comapi(com_apiKey,com_secretKey);
    string symbolcom = "eos_usd";
    //cout << comapi.GetTicker(symbolcom)<<endl;
    string size_depth = "1";
    string merge = "0";
    //cout << comapi.GetDepth(symbolcom,size_depth,merge)<<endl;
    //cout << comapi.DoUserinfo() << endl;

    string future_type = "next_week";
    cout << comapi.DoFuture_Ticker(symbolcom,future_type)<<endl;
    cout << comapi.DoFuture_Hold_amount(symbolcom,future_type)<< endl;
    cout << comapi.DoFuture_Position_4fix(symbolcom,future_type,size_depth)<< endl;

    return;

//	{
//	//现货下单测试
//	string type		= "buy";
//	string price	= "1";
//	string amount	= "0.01";
//	string symbol = "btc_cny";
//    cout << comapi.DoTrade(symbol, type, price, amount)<< endl;								//POST /api/v1/trade						下单交易
//	//{"order_id":88861705,"result":true}
//	string since = "88861705";
//	string order_id	= "88861705";
//    cout << comapi.DoCancel_Order(symbol,order_id) << endl;										//POST /api/v1/order_info					获取用户的订单信息
//	}
	


    {
    //期货下单测试
    string symbolcom		=       "eos_usd";
    string contract_type	=		"this_week";
    string price			=		"6.5";
    string amount			=		"80";
    string type				=		"2";
    string match_price		=		"0";
    string lever_rate		=		"20";

    cout << comapi.DoFuture_Trade(symbolcom,contract_type,price,amount,type,match_price,lever_rate)<<endl; 		//POST /api/v1/future_trade										//POST /api/v1/future_batch_trade		批量下单
    //{"order_id":862348954,"result":true}
    string order_id	= "1242549350640640";
    cout << comapi.DoFuture_Cancel(symbolcom,order_id,contract_type) << endl;

    }


	return 0;
}

