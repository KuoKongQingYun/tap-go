#include "TapQuoteAPI.h"
#include "wrap.h"
/**
 * @brief	设置API的回调接口对象。
 * @details	系统对API的通知将通过设置的回调对象通知给使用者。
 *			ITapQuoteAPINofify是API的回调接口，用户需要继承实现此接口类对象来完成用户需要的功能。
 *			如果用户没有设置回调接口，则API不会向用户返回任何有用的信息。\n
 *			ITapQuoteAPINotify类的详细内容请查看TapQuoteAPI.h 文件。
 * @param[in] apiNotify 实现了ITapQuoteAPINotify接口的对象指针。
 * @operationtype 同步操作
 * @ingroup G_Q_Login
 */
TAPIINT32 ITapQuoteAPI_SetAPINotify(ITapQuoteAPI *pITapQuoteAPI, ITapQuoteAPINotify *apiNotify)
{
    return pITapQuoteAPI->SetAPINotify(apiNotify);
}
/**
 * @brief 设置服务器的IP地址和端口。等到调用Login时真正发起连接。
 * @param[in] IP   IP地址
 * @param[in] port 端口号
 * @operationtype 同步操作
 * @ingroup G_Q_Login
 */
TAPIINT32 ITapQuoteAPI_SetHostAddress(ITapQuoteAPI *pITapQuoteAPI, const TAPICHAR *IP, TAPIUINT16 port)
{
    return pITapQuoteAPI->SetHostAddress(IP, port);
}
/**
 * @brief	发起登录请求。API将先连接服务，建立链路，发起登录认证。
 * @details	在使用函数函数前用户需要完成服务器的设置SetHostAddress()，并且创建TapAPIQuoteLoginAuth类型的用户信息，
 *			并且需要设置好回调接口。\n
 *			连接建立后的用户验证回馈信息通过回调OnLogin()返回给用户。\n
 *			登录成功后API会自动进行API的初始化，API向服务器请求基础数据，查询完以后会通过回调OnAPIReady()
 *			指示用户API初始化完成，可以进行后续的操作了。
 * @param[in] loginAuth 登录验证信息结构指针。包含登录需要的验证信息。
 * @retval 0 登录成功，API开始准备后台数据
 * @retval 非0 错误码
 * @attention 登录成功与否要根据OnLogin回调判断。
 * @operationtype 异步操作
 * @warning	Login()函数调用成功只是代表于服务器建立了链路连接，只有回调OnLogin()的返回能指示用户是否成功登录了。
 * @ingroup G_Q_Login
 */
TAPIINT32 ITapQuoteAPI_Login(ITapQuoteAPI *pITapQuoteAPI, const TapAPIQuoteLoginAuth *loginAuth)
{
    return pITapQuoteAPI->Login(loginAuth);
}
/**
 * @brief	断开和服务器的链路连接。
 * @details	调用函数后API将登出并断开与服务器的连接。
 * @operationtype 异步操作
 * @ingroup G_Q_Disconnect
 */
TAPIINT32 ITapQuoteAPI_Disconnect(ITapQuoteAPI *pITapQuoteAPI)
{
    return pITapQuoteAPI->Disconnect();
}
/**
 * @brief 得到所有品种
 * @param[out] sessionID 返回请求的会话ID。
 * @retval 0 请求成功
 * @retval 非0 错误码
 * @operationtype 异步操作
 * @ingroup G_Q_Commodity
 */
TAPIINT32 ITapQuoteAPI_QryCommodity(ITapQuoteAPI *pITapQuoteAPI, TAPIUINT32 *sessionID)
{
    return pITapQuoteAPI->QryCommodity(sessionID);
}
/**
 * @brief	查询系统中指定品种的合约信息
 * @details	使用此函数前需要先QryCommodity()取得品种信息，
 *			然后选择需要的品种将信息填入TapAPICommodity结构体中完成查询请求。
 * @param[out] sessionID 返回请求的会话ID;
 * @param[in] qryReq 查询系统中指定品种的合约信息请求的结构体指针;\n
 *				    该参数各字段为可选字段，可以用以下方法查询：\n
 *					1.全部留空：查所有合约\n
 *					2.仅交易所编码有效：查该交易所下所有品种的合约\n
 *					3.交易所编码和品种类型有效：查该交易所下指定品种类型的合约\n
 *					4.交易所编码、品种类型和品种编码都有效：查该品种下的所有合约
 * @retval 0 请求成功
 * @retval 非0 错误码
 * @operationtype 异步操作
 * @ingroup G_Q_Contract
 */
TAPIINT32 ITapQuoteAPI_QryContract(ITapQuoteAPI *pITapQuoteAPI, TAPIUINT32 *sessionID, const TapAPICommodity *qryReq)
{
    return pITapQuoteAPI->QryContract(sessionID, qryReq);
}
/**
 * @brief	订阅指定合约的行情
 * @details	函数向服务器请求contract描述的合约的行情信息，行情订阅成功后服务器将持续向用户推送行情信息，
 *			直到用户退订行情信息或者断开于服务器的通信。\n
 *			调用此函数前先获取合约信息，然后从合约信息中取出合约填入contract。\n
 * @param[out] sessionID 返回请求的会话ID。
 * @param[in] contract 指定合约。
 * @retval 0 请求成功
 * @retval 非0 错误码
 * @operationtype 异步操作
 * @ingroup G_Q_Quote
 */
TAPIINT32 ITapQuoteAPI_SubscribeQuote(ITapQuoteAPI *pITapQuoteAPI, TAPIUINT32 *sessionID, const TapAPIContract *contract)
{
    return pITapQuoteAPI->SubscribeQuote(sessionID, contract);
}
/**
 * @brief	退订指定合约的行情
 * @details	退订已经订阅的行情信息。
 * @param[out] sessionID 返回请求的会话ID；
 * @param[in]	contract 指定合约。
 * @retval 0 请求成功
 * @retval 非0 错误码
 * @operationtype 异步操作
 * @ingroup G_Q_Quote
 */
TAPIINT32 ITapQuoteAPI_UnSubscribeQuote(ITapQuoteAPI *pITapQuoteAPI, TAPIUINT32 *sessionID, const TapAPIContract *contract)
{
    return pITapQuoteAPI->UnSubscribeQuote(sessionID, contract);
}