/*
 * SZTBTicketAPI.cpp
 *
 *  Created on: 2016年8月10日
 *      Author: wangqi
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include "SZTBTicketAPI.h"
#include "assert.h"

int PackDateTime(const DATETIME* dateTime, char* buf);

//获得班次信息
SZTBTICKET_API  int  SZTBTicket_ParseBaseSchedule(const char* pData,int nDataLen,T_CCMS_TICKET_BASESCHEDULE* pParam)
{
	//printf("enter Ticket_BaseSchedule\n");
	int nReadPos = 0;
	int Length = sizeof(T_CCMS_TICKET_BASESCHEDULE);

	if(pData == NULL || nDataLen <= 0)
	return CCMS_ERRORMSG_FAIL;

	if(nDataLen < Length){
		return  CCMS_ERRORMSG_FAIL;
	}
	else{
		memset(pParam->chFServerSN,0,12);
		memcpy(pParam->chFServerSN,pData+nReadPos,12);
		nReadPos += 12;

		memset(pParam->chGuid,0,40);
		memcpy(pParam->chGuid,pData+nReadPos,40);
		nReadPos += 40;

		memset(pParam->chGlobalCode,0,10);
		memcpy(pParam->chGlobalCode,pData+nReadPos,10);
		nReadPos += 10;

		memset(pParam->chStationCode,0,8);
		memcpy(pParam->chStationCode,pData+nReadPos,8);
		nReadPos += 8;

		memset(pParam->chStationName,0,80);
		memcpy(pParam->chStationName,pData+nReadPos,80);
		nReadPos += 80;

		memset(pParam->chLocalCode,0,20);
		memcpy(pParam->chLocalCode,pData+nReadPos,20);
		nReadPos += 20;

		memset(pParam->chLineName,0,80);
		memcpy(pParam->chLineName,pData+nReadPos,80);
		nReadPos += 80;

		memset(pParam->chTransType,0,10);
		memcpy(pParam->chTransType,pData+nReadPos,10);
		nReadPos += 10;

		memset(pParam->chLineKind,0,20);
		memcpy(pParam->chLineKind,pData+nReadPos,20);
		nReadPos += 20;

		memset(pParam->chSchKind,0,20);
		memcpy(pParam->chSchKind,pData+nReadPos,20);
		nReadPos += 20;

		memset(pParam->chSchType,0,20);
		memcpy(pParam->chSchType,pData+nReadPos,20);
		nReadPos += 20;

		memset(pParam->chSchMode,0,10);
		memcpy(pParam->chSchMode,pData+nReadPos,10);
		nReadPos += 10;

		memset(pParam->chStartTime,0,4);
		memcpy(pParam->chStartTime,pData+nReadPos,4);
		nReadPos += 4;

		memset(pParam->chEndTime,0,4);
		memcpy(pParam->chEndTime,pData+nReadPos,4);
		nReadPos += 4;

		memset(&pParam->nRotationInterval,0,2);
		memcpy(&pParam->nRotationInterval,pData+nReadPos,2);
		nReadPos += 2;

		memset(pParam->chTime,0,4);
		memcpy(pParam->chTime,pData+nReadPos,4);
		nReadPos += 4;

		memset(pParam->chEndProvince,0,90);
		memcpy(pParam->chEndProvince,pData+nReadPos,90);
		nReadPos += 90;

		memset(pParam->chEndCity,0,90);
		memcpy(pParam->chEndCity,pData+nReadPos,90);
		nReadPos += 90;

		memset(pParam->chEndCounty,0,20);
		memcpy(pParam->chEndCounty,pData+nReadPos,20);
		nReadPos += 20;

		memset(pParam->chEndTown,0,20);
		memcpy(pParam->chEndTown,pData+nReadPos,20);
		nReadPos += 20;

		memset(pParam->chVillage,0,20);
		memcpy(pParam->chVillage,pData+nReadPos,20);
		nReadPos += 20;

		memset(pParam->chEndNodeCode,0,20);
		memcpy(pParam->chEndNodeCode,pData+nReadPos,20);
		nReadPos += 20;

		memset(pParam->chEndNodeName,0,50);
		memcpy(pParam->chEndNodeName,pData+nReadPos,50);
		nReadPos += 50;

		memset(pParam->chStartValidDate,0,8);
		memcpy(pParam->chStartValidDate,pData+nReadPos,8);
		nReadPos += 8;

		memset(pParam->chEndValidDate,0,8);
		memcpy(pParam->chEndValidDate,pData+nReadPos,8);
		nReadPos += 8;

		memset(pParam->chStatus,0,10);
		memcpy(pParam->chStatus,pData+nReadPos,10);
		nReadPos += 10;

		UInt8 Data_Buf[7];
		memset(Data_Buf,0,7);
		memset(&pParam->dtUploadTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtUploadTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtUploadTime.nMonth = Data_Buf[2];
		pParam->dtUploadTime.nDay = Data_Buf[3];
		pParam->dtUploadTime.nHour = Data_Buf[4];
		pParam->dtUploadTime.nMinute = Data_Buf[5];
		pParam->dtUploadTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		memset(Data_Buf,0,7);
		memset(&pParam->dtCreateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtCreateTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtCreateTime.nMonth = Data_Buf[2];
		pParam->dtCreateTime.nDay = Data_Buf[3];
		pParam->dtCreateTime.nHour = Data_Buf[4];
		pParam->dtCreateTime.nMinute = Data_Buf[5];
		pParam->dtCreateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		memset(Data_Buf,0,7);
		memset(&pParam->dtUpdateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtUpdateTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtUpdateTime.nMonth = Data_Buf[2];
		pParam->dtUpdateTime.nDay = Data_Buf[3];
		pParam->dtUpdateTime.nHour = Data_Buf[4];
		pParam->dtUpdateTime.nMinute = Data_Buf[5];
		pParam->dtUpdateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		if(nReadPos == Length){
			return CCMS_RETURN_OK;
		}
		else{
			return CCMS_ERRORMSG_FAIL;
		}
	}

}

//班次信息--车辆信息
SZTBTICKET_API  int  SZTBTicket_ParseBaseScheduleDetail(const char* pData,int nDataLen,T_CCMS_TICKET_BASESCHEDULE_DETAIL* pParam)
{
	int nReadPos = 0;
	int Length = sizeof(T_CCMS_TICKET_BASESCHEDULE_DETAIL);

	if(pData == NULL || nDataLen <= 0)
		return CCMS_ERRORMSG_FAIL;

	if(nDataLen < Length){
		return  CCMS_ERRORMSG_FAIL;
	}
	else{
		memset(pParam->chFServerSN,0,12);
		memcpy(pParam->chFServerSN,pData+nReadPos,12);
		nReadPos += 12;

		memset(pParam->chGuid,0,40);
		memcpy(pParam->chGuid,pData+nReadPos,40);
		nReadPos += 40;

		memset(pParam->chParentID,0,40);
		memcpy(pParam->chParentID,pData+nReadPos,40);
		nReadPos += 40;

		memset(pParam->chStationCode,0,8);
		memcpy(pParam->chStationCode,pData+nReadPos,8);
		nReadPos += 8;

		memset(pParam->chLocalCode,0,20);
		memcpy(pParam->chLocalCode,pData+nReadPos,20);
		nReadPos += 20;

		memset(pParam->chEnterpriseCode,0,15);
		memcpy(pParam->chEnterpriseCode,pData+nReadPos,15);
		nReadPos += 15;

		memset(pParam->chEnterpriseName,0,80);
		memcpy(pParam->chEnterpriseName,pData+nReadPos,80);
		nReadPos += 80;

		memset(pParam->chBusCode,0,50);
		memcpy(pParam->chBusCode,pData+nReadPos,50);
		nReadPos += 50;

		memset(&pParam->nSeatCount,0,1);
		memcpy(&pParam->nSeatCount,pData+nReadPos,1);
		nReadPos += 1;

		memset(&pParam->chBusinessBus,0,1);
		memcpy(&pParam->chBusinessBus,pData+nReadPos,1);
		nReadPos += 1;

		memset(pParam->chBusType,0,10);
		memcpy(pParam->chBusType,pData+nReadPos,10);
		nReadPos += 10;

		memset(pParam->chSeatType,0,10);
		memcpy(pParam->chSeatType,pData+nReadPos,10);
		nReadPos += 10;

		memset(pParam->chBusLevel,0,40);
		memcpy(pParam->chBusLevel,pData+nReadPos,40);
		nReadPos += 40;

		UInt8 Data_Buf[7] = {0};
		memset(Data_Buf,0,7);
		memset(&pParam->dtCreateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtCreateTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtCreateTime.nMonth = Data_Buf[2];
		pParam->dtCreateTime.nDay = Data_Buf[3];
		pParam->dtCreateTime.nHour = Data_Buf[4];
		pParam->dtCreateTime.nMinute = Data_Buf[5];
		pParam->dtCreateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		memset(Data_Buf,0,7);
		memset(&pParam->dtUpdateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtUpdateTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtUpdateTime.nMonth = Data_Buf[2];
		pParam->dtUpdateTime.nDay = Data_Buf[3];
		pParam->dtUpdateTime.nHour = Data_Buf[4];
		pParam->dtUpdateTime.nMinute = Data_Buf[5];
		pParam->dtUpdateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		if(nReadPos == Length){
			return CCMS_RETURN_OK;
		}
		else{
			return CCMS_ERRORMSG_FAIL;
		}
	}
}

//班次信息--票价信息
SZTBTICKET_API  int  SZTBTicket_ParseBaseSchedulePrice(const char* pData,int nDataLen,T_CCMS_TICKET_BASESCHEDULEPRICE* pParam)
{
	int nReadPos = 0;
	int Length = sizeof(T_CCMS_TICKET_BASESCHEDULEPRICE);

	if(pData == NULL || nDataLen <= 0)
	return CCMS_ERRORMSG_FAIL;

	if(nDataLen < Length){
		return CCMS_ERRORMSG_FAIL;
	}
	else{
		memset(pParam->chFServerSN,0,12);
		memcpy(pParam->chFServerSN,pData+nReadPos,12);
		nReadPos += 12;

		memset(pParam->chGuid,0,40);
		memcpy(pParam->chGuid,pData+nReadPos,40);
		nReadPos += 40;

		memset(pParam->chParentID,0,40);
		memcpy(pParam->chParentID,pData+nReadPos,40);
		nReadPos += 40;

		memset(pParam->chStationCode,0,8);
		memcpy(pParam->chStationCode,pData+nReadPos,8);
		nReadPos += 8;

		memset(pParam->chLocalCode,0,20);
		memcpy(pParam->chLocalCode,pData+nReadPos,20);
		nReadPos += 20;

		memset(pParam->chNodeName,0,100);
		memcpy(pParam->chNodeName,pData+nReadPos,100);
		nReadPos += 100;

		memset(pParam->chNodeCode,0,10);
		memcpy(pParam->chNodeCode,pData+nReadPos,10);
		nReadPos += 10;

		memset(pParam->chTravelTime,0,4);
		memcpy(pParam->chTravelTime,pData+nReadPos,4);
		nReadPos += 4;

		memset(&pParam->flMileage,0,8);
		memcpy(&pParam->flMileage,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flTransPrice,0,8);
		memcpy(&pParam->flTransPrice,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flSingle,0,8);
		memcpy(&pParam->flSingle,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flSingleTripToll,0,8);
		memcpy(&pParam->flSingleTripToll,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flBunkerSurcharge,0,8);
		memcpy(&pParam->flBunkerSurcharge,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flStationFee,0,8);
		memcpy(&pParam->flStationFee,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flOtherFee,0,8);
		memcpy(&pParam->flOtherFee,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flTransFee,0,8);
		memcpy(&pParam->flTransFee,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flUpperPrice,0,8);
		memcpy(&pParam->flUpperPrice,pData+nReadPos,8);
		//printf("flUpperPrice:%f\n",pParam->pPrice[i].flUpperPrice);
		nReadPos += 8;

		memset(&pParam->flPrice,0,8);
		memcpy(&pParam->flPrice,pData+nReadPos,8);
		//printf("flPrice:%f\n",pParam->pPrice[i].flPrice);
		nReadPos += 8;

		memset(&pParam->flHalfprice,0,8);
		memcpy(&pParam->flHalfprice,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flStdPrice,0,8);
		memcpy(&pParam->flStdPrice,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flDisabilitySoldierPrice,0,8);
		memcpy(&pParam->flDisabilitySoldierPrice,pData+nReadPos,8);
		nReadPos += 8;

		memset(pParam->chValidityStart,0,8);
		memcpy(pParam->chValidityStart,pData+nReadPos,8);
		nReadPos += 8;

		memset(pParam->chValidityEnd,0,8);
		memcpy(pParam->chValidityEnd,pData+nReadPos,8);
		nReadPos += 8;

		UInt8 Data_Buf[7] = {0};
		memset(Data_Buf,0,7);
		memset(&pParam->dtCreateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtCreateTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtCreateTime.nMonth = Data_Buf[2];
		pParam->dtCreateTime.nDay = Data_Buf[3];
		pParam->dtCreateTime.nHour = Data_Buf[4];
		pParam->dtCreateTime.nMinute = Data_Buf[5];
		pParam->dtCreateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		memset(Data_Buf,0,7);
		memset(&pParam->dtUpdateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtUpdateTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtUpdateTime.nMonth = Data_Buf[2];
		pParam->dtUpdateTime.nDay = Data_Buf[3];
		pParam->dtUpdateTime.nHour = Data_Buf[4];
		pParam->dtUpdateTime.nMinute = Data_Buf[5];
		pParam->dtUpdateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		if(nReadPos == Length){
			return CCMS_RETURN_OK;
		}
		else{
			return CCMS_ERRORMSG_FAIL;
		}
	}
}

//获得发班班次
SZTBTICKET_API  int  SZTBTicket_ParseSchedule(const char* pData,int nDataLen,T_CCMS_TICKET_SCHEDULE* pParam)
{
	int nReadPos = 0;
	int Length = sizeof(T_CCMS_TICKET_SCHEDULE);

	if(pData == NULL || nDataLen <= 0)
	return CCMS_ERRORMSG_FAIL;

	if(nDataLen < Length){
		return CCMS_ERRORMSG_FAIL;
	}
	else{
		memset(&pParam->chFServerSN,0,12);
		memcpy(&pParam->chFServerSN,pData+nReadPos,12);
		nReadPos += 12;

		memset(&pParam->chGuid,0,40);
		memcpy(&pParam->chGuid,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chGlobalCode,0,10);
		memcpy(&pParam->chGlobalCode,pData+nReadPos,10);
		nReadPos += 10;

		memset(&pParam->chStationCode,0,8);
		memcpy(&pParam->chStationCode,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->chStationName,0,80);
		memcpy(&pParam->chStationName,pData+nReadPos,80);
		nReadPos += 80;

		memset(&pParam->chLocalCode,0,20);
		memcpy(&pParam->chLocalCode,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chLineName,0,80);
		memcpy(&pParam->chLineName,pData+nReadPos,80);
		nReadPos += 80;

		memset(&pParam->chTransType,0,10);
		memcpy(&pParam->chTransType,pData+nReadPos,10);
		nReadPos += 10;

		memset(&pParam->chLineKind,0,20);
		memcpy(&pParam->chLineKind,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chSchKind,0,20);
		memcpy(&pParam->chSchKind,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chSchType,0,20);
		memcpy(&pParam->chSchType,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chSchMode,0,10);
		memcpy(&pParam->chSchMode,pData+nReadPos,10);
		nReadPos += 10;

		memset(&pParam->chStartTime,0,4);
		memcpy(&pParam->chStartTime,pData+nReadPos,4);
		nReadPos += 4;

		memset(&pParam->chEndTime,0,4);
		memcpy(&pParam->chEndTime,pData+nReadPos,4);
		nReadPos += 4;

		memset(&pParam->nRotationInterval,0,2);
		memcpy(&pParam->nRotationInterval,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->chTime,0,4);
		memcpy(&pParam->chTime,pData+nReadPos,4);
		nReadPos += 4;

		memset(&pParam->chDate,0,8);
		memcpy(&pParam->chDate,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->chEndProvince,0,90);
		memcpy(&pParam->chEndProvince,pData+nReadPos,90);
		nReadPos += 90;

		memset(&pParam->chEndCity,0,90);
		memcpy(&pParam->chEndCity,pData+nReadPos,90);
		nReadPos += 90;

		memset(&pParam->chEndCounty,0,50);
		memcpy(&pParam->chEndCounty,pData+nReadPos,50);
		nReadPos += 50;

		memset(&pParam->chEndTown,0,50);
		memcpy(&pParam->chEndTown,pData+nReadPos,50);
		nReadPos += 50;

		memset(&pParam->chVillage,0,50);
		memcpy(&pParam->chVillage,pData+nReadPos,50);
		nReadPos += 50;

		memset(&pParam->chEndNodeCode,0,20);
		memcpy(&pParam->chEndNodeCode,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chEndNodeName,0,50);
		memcpy(&pParam->chEndNodeName,pData+nReadPos,50);
		nReadPos += 50;

		memset(&pParam->chStatus,0,20);
		memcpy(&pParam->chStatus,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->nSeatCount,0,2);
		memcpy(&pParam->nSeatCount,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->nTicketSale,0,2);
		memcpy(&pParam->nTicketSale,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->nTicketSell,0,2);
		memcpy(&pParam->nTicketSell,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->nTicketCount,0,2);
		memcpy(&pParam->nTicketCount,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->nFreeChildrenTicketSale,0,2);
		memcpy(&pParam->nFreeChildrenTicketSale,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->chEnterpriseCode,0,15);
		memcpy(&pParam->chEnterpriseCode,pData+nReadPos,15);
		nReadPos += 15;

		memset(&pParam->chEnterpriseName,0,80);
		memcpy(&pParam->chEnterpriseName,pData+nReadPos,80);
		nReadPos += 80;

		memset(&pParam->chBusCode,0,50);
		memcpy(&pParam->chBusCode,pData+nReadPos,50);
		nReadPos += 50;

		memset(&pParam->bBusinessBus,0,1);
		memcpy(&pParam->bBusinessBus,pData+nReadPos,1);
		nReadPos += 1;

		memset(&pParam->chBusType,0,10);
		memcpy(&pParam->chBusType,pData+nReadPos,10);
		nReadPos += 10;

		memset(&pParam->chSeatType,0,10);
		memcpy(&pParam->chSeatType,pData+nReadPos,10);
		nReadPos += 10;

		memset(&pParam->chBusLevel,0,40);
		memcpy(&pParam->chBusLevel,pData+nReadPos,40);
		nReadPos += 40;

		UInt8 Data_Buf[7];
		memset(Data_Buf,0,7);
		memset(&pParam->dtUploadTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtUploadTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtUploadTime.nMonth = Data_Buf[2];
		pParam->dtUploadTime.nDay = Data_Buf[3];
		pParam->dtUploadTime.nHour = Data_Buf[4];
		pParam->dtUploadTime.nMinute = Data_Buf[5];
		pParam->dtUploadTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		memset(Data_Buf,0,7);
		memset(&pParam->dtUpdateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtUpdateTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtUpdateTime.nMonth = Data_Buf[2];
		pParam->dtUpdateTime.nDay = Data_Buf[3];
		pParam->dtUpdateTime.nHour = Data_Buf[4];
		pParam->dtUpdateTime.nMinute = Data_Buf[5];
		pParam->dtUpdateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		if(nReadPos == Length){
			return CCMS_RETURN_OK;
		}
		else{
			return CCMS_ERRORMSG_FAIL;
		}
	}

}

//发班班次--票价信息明细
SZTBTICKET_API  int  SZTBTicket_ParseScheduleDetail(const char* pData,int nDataLen,T_CCMS_TICKET_SCHEDULEDETAIL* pParam)
{
	int nReadPos = 0;
	int Length = sizeof(T_CCMS_TICKET_SCHEDULEDETAIL);

	if(pData == NULL || nDataLen <= 0)
	return CCMS_ERRORMSG_FAIL;

	if(nDataLen < Length){
		return CCMS_ERRORMSG_FAIL;
	}
	else{
		memset(pParam->chFServerSN,0,12);
		memcpy(pParam->chFServerSN,pData+nReadPos,12);
		nReadPos += 12;

		memset(&pParam->chGuid,0,40);
		memcpy(&pParam->chGuid,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chParentID,0,40);
		memcpy(&pParam->chParentID,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chStationCode,0,8);
		memcpy(&pParam->chStationCode,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->chLocalCode,0,20);
		memcpy(&pParam->chLocalCode,pData+nReadPos,20);
		nReadPos += 20;


		memset(&pParam->chDate,0,8);
		memcpy(&pParam->chDate,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->chNodeCode,0,10);
		memcpy(&pParam->chNodeCode,pData+nReadPos,10);
		nReadPos += 10;

		memset(&pParam->chNodeName,0,100);
		memcpy(&pParam->chNodeName,pData+nReadPos,100);
		nReadPos += 100;

		memset(&pParam->flTravelTime,0,8);
		memcpy(&pParam->flTravelTime,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flMileage,0,8);
		memcpy(&pParam->flMileage,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flUpperPrice,0,8);
		memcpy(&pParam->flUpperPrice,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flPrice,0,8);
		memcpy(&pParam->flPrice,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flHalfprice,0,8);
		memcpy(&pParam->flHalfprice,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flStdPrice,0,8);
		memcpy(&pParam->flStdPrice,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flDisabilitySoldierPrice,0,8);
		memcpy(&pParam->flDisabilitySoldierPrice,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->nFullTicketSale,0,2);
		memcpy(&pParam->nFullTicketSale,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->nHalfTicketSale,0,2);
		memcpy(&pParam->nHalfTicketSale,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->nFreeTicketSale,0,2);
		memcpy(&pParam->nFreeTicketSale,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->nStdTicketSale,0,2);
		memcpy(&pParam->nStdTicketSale,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->nDisabilitySoldierTicketSell,0,2);
		memcpy(&pParam->nDisabilitySoldierTicketSell,pData+nReadPos,2);
		nReadPos += 2;

		UInt8 Data_Buf[7] = {0};
		memset(Data_Buf,0,7);
		memset(&pParam->dtCreateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtCreateTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtCreateTime.nMonth = Data_Buf[2];
		pParam->dtCreateTime.nDay = Data_Buf[3];
		pParam->dtCreateTime.nHour = Data_Buf[4];
		pParam->dtCreateTime.nMinute = Data_Buf[5];
		pParam->dtCreateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		memset(Data_Buf,0,7);
		memset(&pParam->dtUpdateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtUpdateTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtUpdateTime.nMonth = Data_Buf[2];
		pParam->dtUpdateTime.nDay = Data_Buf[3];
		pParam->dtUpdateTime.nHour = Data_Buf[4];
		pParam->dtUpdateTime.nMinute = Data_Buf[5];
		pParam->dtUpdateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		if(nReadPos == Length){
			return CCMS_RETURN_OK;
		}
		else{
			return CCMS_ERRORMSG_FAIL;
		}
	}

}

//获得发班信息
SZTBTICKET_API  int  SZTBTicket_ParseSendSchedule(const char* pData,int nDataLen,T_CCMS_TICKET_SENDSCHEDULE* pParam)
{
	int nReadPos = 0;
	int Length = sizeof(T_CCMS_TICKET_SENDSCHEDULE);

	if(pData == NULL || nDataLen <= 0)
		return CCMS_ERRORMSG_FAIL;

	if(nDataLen < Length){
		return CCMS_ERRORMSG_FAIL;
	}
	else{
		memset(&pParam->chFServerSN,0,12);
		memcpy(&pParam->chFServerSN,pData+nReadPos,12);
		nReadPos += 12;

		memset(&pParam->chGuid,0,40);
		memcpy(&pParam->chGuid,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chGlobalCode,0,10);
		memcpy(&pParam->chGlobalCode,pData+nReadPos,10);
		nReadPos += 10;

		memset(&pParam->chStationCode,0,8);
		memcpy(&pParam->chStationCode,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->chStationName,0,80);
		memcpy(&pParam->chStationName,pData+nReadPos,80);
		nReadPos += 80;

		memset(&pParam->chBusIC,0,20);
		memcpy(&pParam->chBusIC,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chBusCode,0,20);
		memcpy(&pParam->chBusCode,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chBusColor,0,10);
		memcpy(&pParam->chBusColor,pData+nReadPos,10);
		nReadPos += 10;

		memset(&pParam->chEnterpriseCode,0,15);
		memcpy(&pParam->chEnterpriseCode,pData+nReadPos,15);
		nReadPos += 15;

		memset(&pParam->chEnterpriseName,0,80);
		memcpy(&pParam->chEnterpriseName,pData+nReadPos,80);
		nReadPos += 80;

		memset(&pParam->chLocalCode,0,20);
		memcpy(&pParam->chLocalCode,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chDate,0,8);
		memcpy(&pParam->chDate,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->chTime,0,4);
		memcpy(&pParam->chTime,pData+nReadPos,4);
		nReadPos += 4;

		memset(&pParam->chInTime,0,4);
		memcpy(&pParam->chInTime,pData+nReadPos,4);
		nReadPos += 4;

		memset(&pParam->chOutTime,0,4);
		memcpy(&pParam->chOutTime,pData+nReadPos,4);
		nReadPos += 4;

		memset(&pParam->chSafeCheck,0,6);
		memcpy(&pParam->chSafeCheck,pData+nReadPos,6);
		nReadPos += 6;

		memset(&pParam->nPassenger,0,2);
		memcpy(&pParam->nPassenger,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->nPassengerIn,0,2);
		memcpy(&pParam->nPassengerIn,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->nPassengerFee,0,2);
		memcpy(&pParam->nPassengerFee,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->nChild,0,2);
		memcpy(&pParam->nChild,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->nPassengerOut,0,2);
		memcpy(&pParam->nPassengerOut,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->chOper,0,20);
		memcpy(&pParam->chOper,pData+nReadPos,20);
		nReadPos += 20;

		UInt8 Data_Buf[7];
		memset(Data_Buf,0,7);
		memset(&pParam->dtOpTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtOpTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtOpTime.nMonth =  Data_Buf[2];
		pParam->dtOpTime.nDay =  Data_Buf[3];
		pParam->dtOpTime.nHour =  Data_Buf[4];
		pParam->dtOpTime.nMinute =  Data_Buf[5];
		pParam->dtOpTime.nSecond =  Data_Buf[6];
		nReadPos += 7;

		memset(Data_Buf,0,7);
		memset(&pParam->dtUploadTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtUploadTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtUploadTime.nMonth = Data_Buf[2];
		pParam->dtUploadTime.nDay = Data_Buf[3];
		pParam->dtUploadTime.nHour = Data_Buf[4];
		pParam->dtUploadTime.nMinute = Data_Buf[5];
		pParam->dtUploadTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		memset(&pParam->chIsSafeSuper,0,50);
		memcpy(&pParam->chIsSafeSuper,pData+nReadPos,50);
		nReadPos += 50;

		memset(&pParam->chRoadTransCode,0,40);
		memcpy(&pParam->chRoadTransCode,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chSeatType,0,10);
		memcpy(&pParam->chSeatType,pData+nReadPos,10);
		nReadPos += 10;

		memset(&pParam->chBusLevel,0,40);
		memcpy(&pParam->chBusLevel,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chTechLevel,0,40);
		memcpy(&pParam->chTechLevel,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chCarValid,0,8);
		memcpy(pParam->chCarValid,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->chMarkCarCode,0,40);
		memcpy(&pParam->chMarkCarCode,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chLineName,0,80);
		memcpy(&pParam->chLineName,pData+nReadPos,80);
		nReadPos += 80;

		memset(&pParam->chThroughLine,0,255);
		memcpy(&pParam->chThroughLine,pData+nReadPos,255);
		nReadPos += 255;

		memset(&pParam->chNodes,0,255);
		memcpy(&pParam->chNodes,pData+nReadPos,255);
		nReadPos += 255;

		memset(&pParam->chEndNodeCode,0,20);
		memcpy(&pParam->chEndNodeCode,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chEndNodeName,0,50);
		memcpy(&pParam->chEndNodeName,pData+nReadPos,50);
		nReadPos += 50;

		memset(&pParam->chSchKind,0,20);
		memcpy(&pParam->chSchKind,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chSchType,0,20);
		memcpy(&pParam->chSchType,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chSchMode,0,10);
		memcpy(&pParam->chSchMode,pData+nReadPos,10);
		nReadPos += 10;

		memset(&pParam->chDrivingLicenseValid,0,8);
		memcpy(&pParam->chDrivingLicenseValid,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->bIsDanger,0,1);
		memcpy(&pParam->bIsDanger,pData+nReadPos,1);
		nReadPos += 1;

		memset(&pParam->chDangerName,0,255);
		memcpy(&pParam->chDangerName,pData+nReadPos,255);
		nReadPos += 255;

		memset(&pParam->bIsSafetyBelt,0,1);
		memcpy(&pParam->bIsSafetyBelt,pData+nReadPos,1);
		nReadPos += 1;

		memset(&pParam->bIsOverman,0,1);
		memcpy(&pParam->bIsOverman,pData+nReadPos,1);
		nReadPos += 1;

		memset(&pParam->chDriver1,0,20);
		memcpy(&pParam->chDriver1,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chDriverCer1,0,20);
		memcpy(&pParam->chDriverCer1,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->bDriverValid1,0,1);
		memcpy(&pParam->bDriverValid1,pData+nReadPos,1);
		nReadPos += 1;

		memset(&pParam->chDriver2,0,20);
		memcpy(&pParam->chDriver2,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chDriverCer2,0,20);
		memcpy(&pParam->chDriverCer2,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->bDriverValid2,0,1);
		memcpy(&pParam->bDriverValid2,pData+nReadPos,1);
		nReadPos += 1;

		memset(&pParam->chDriver3,0,20);
		memcpy(&pParam->chDriver3,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chDriverCer3,0,20);
		memcpy(&pParam->chDriverCer3,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->bDriverValid3,0,1);
		memcpy(&pParam->bDriverValid3,pData+nReadPos,1);
		nReadPos += 1;

		memset(Data_Buf,0,7);
		memset(&pParam->dtCreateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtCreateTime.nYear = (Data_Buf[0] << 8) | Data_Buf[1];
		pParam->dtCreateTime.nMonth = Data_Buf[2];
		pParam->dtCreateTime.nDay = Data_Buf[3];
		pParam->dtCreateTime.nHour = Data_Buf[4];
		pParam	->dtCreateTime.nMinute = Data_Buf[5];
		pParam	->dtCreateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		memset(Data_Buf,0,7);
		memset(&pParam->dtUpdateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtUpdateTime.nYear = (Data_Buf[0] << 8) |Data_Buf[1];
		pParam->dtUpdateTime.nMonth = Data_Buf[2];
		pParam->dtUpdateTime.nDay = Data_Buf[3];
		pParam->dtUpdateTime.nHour = Data_Buf[4];
		pParam->dtUpdateTime.nMinute = Data_Buf[5];
		pParam->dtUpdateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		if(nReadPos == Length){
			return CCMS_RETURN_OK;
		}
		else{
			return CCMS_ERRORMSG_FAIL;
		}
	}

}

//发班信息--到站明细
SZTBTICKET_API  int  SZTBTicket_ParseSendScheduleDetail(const char* pData,int nDataLen,T_CCMS_TICKET_SENDSCHEDULEDETAIL* pParam)
{
	int nReadPos = 0;
	int Length = sizeof(T_CCMS_TICKET_SENDSCHEDULEDETAIL);

	if(pData == NULL || nDataLen <= 0)
		return CCMS_ERRORMSG_FAIL;

	if(nDataLen < Length){
		return CCMS_ERRORMSG_FAIL;
	}
	else{
		memset(pParam->chFServerSN,0,12);
		memcpy(pParam->chFServerSN,pData+nReadPos,12);
		nReadPos += 12;

		memset(&pParam->chGuid,0,40);
		memcpy(&pParam->chGuid,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chParentID,0,40);
		memcpy(&pParam->chParentID,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chStationCode,0,8);
		memcpy(&pParam->chStationCode,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->chDate,0,8);
		memcpy(&pParam->chDate,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->chLocalCode,0,20);
		memcpy(&pParam->chLocalCode,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chNodeCode,0,20);
		memcpy(&pParam->chNodeCode,pData+nReadPos,20);
		nReadPos += 20;


		memset(&pParam->chNodeName,0,50);
		memcpy(&pParam->chNodeName,pData+nReadPos,50);
		nReadPos += 50;

		memset(&pParam->nNodeNumber,0,2);
		memcpy(&pParam->nNodeNumber,pData+nReadPos,2);
		nReadPos += 2;

		UInt8 Data_Buf[7];
		memset(Data_Buf,0,7);
		memset(&pParam->dtCreateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtCreateTime.nYear = (Data_Buf[0] << 8) |Data_Buf[1];
		pParam->dtCreateTime.nMonth = Data_Buf[2];
		pParam->dtCreateTime.nDay = Data_Buf[3];
		pParam->dtCreateTime.nHour = Data_Buf[4];
		pParam->dtCreateTime.nMinute = Data_Buf[5];
		pParam->dtCreateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		memset(Data_Buf,0,7);
		memset(&pParam->dtUpdateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtUpdateTime.nYear = (Data_Buf[0] << 8) |Data_Buf[1];
		pParam->dtUpdateTime.nMonth = Data_Buf[2];
		pParam->dtUpdateTime.nDay = Data_Buf[3];
		pParam->dtUpdateTime.nHour = Data_Buf[4];
		pParam->dtUpdateTime.nMinute = Data_Buf[5];
		pParam->dtUpdateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		if(nReadPos == Length){
			return CCMS_RETURN_OK;
		}
		else{
			return CCMS_ERRORMSG_FAIL;
		}
	}

}

//获得订单
SZTBTICKET_API  int  SZTBTicket_ParseOrderUpload(const char* pData,int nDataLen,CCMS_TICKET_ORDERUPLOAD* pParam)
{
	int nReadPos = 0;
	int Length = sizeof(T_CCMS_TICKET_ORDERUPLOAD);
	if(pData == NULL || nDataLen <= 0)
	return CCMS_ERRORMSG_FAIL;

	if(nDataLen < Length){
		return CCMS_ERRORMSG_FAIL;
	}
	else{
		memset(&pParam->chFServerSN,0,12);
		memcpy(&pParam->chFServerSN,pData+nReadPos,12);
		nReadPos += 12;

		memset(&pParam->chGuid,0,40);
		memcpy(&pParam->chGuid,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chAgentCode,0,20);
		memcpy(&pParam->chAgentCode,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chStationCode,0,10);
		memcpy(&pParam->chStationCode,pData+nReadPos,10);
		nReadPos += 10;

		memset(&pParam->chStationName,0,80);
		memcpy(&pParam->chStationName,pData+nReadPos,80);
		nReadPos += 80;

		memset(&pParam->chOrderNo,0,30);
		memcpy(&pParam->chOrderNo,pData+nReadPos,30);
		nReadPos += 30;

		memset(&pParam->chScheduleNo,0,20);
		memcpy(&pParam->chScheduleNo,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->nTicketCount,0,2);
		memcpy(&pParam->nTicketCount,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->flTicketAmount,0,8);
		memcpy(&pParam->flTicketAmount,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flAgentFee,0,8);
		memcpy(&pParam->flAgentFee,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->flRefundFee,0,8);
		memcpy(&pParam->flRefundFee,pData+nReadPos,8);
		nReadPos += 8;

		memset(&pParam->chBarCodes,0,255);
		memcpy(&pParam->chBarCodes,pData+nReadPos,255);
		nReadPos += 255;

		memset(&pParam->chTicketNos,0,255);
		memcpy(&pParam->chTicketNos,pData+nReadPos,255);
		nReadPos += 255;

		memset(&pParam->nRequestType,0,2);
		memcpy(&pParam->nRequestType,pData+nReadPos,2);
		nReadPos += 2;

		memset(&pParam->chTransStatus,0,15);
		memcpy(&pParam->chTransStatus,pData+nReadPos,15);
		nReadPos += 15;

		memset(&pParam->nUploadMemberType,0,2);
		memcpy(&pParam->nUploadMemberType,pData+nReadPos,2);
		nReadPos += 2;

		UInt8 Data_Buf[7];
		memset(Data_Buf,0,7);
		memset(&pParam->dtOrderTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtOrderTime.nYear = (Data_Buf[0] << 8) |Data_Buf[1];
		pParam->dtOrderTime.nMonth = Data_Buf[2];
		pParam->dtOrderTime.nDay = Data_Buf[3];
		pParam->dtOrderTime.nHour = Data_Buf[4];
		pParam->dtOrderTime.nMinute = Data_Buf[5];
		pParam->dtOrderTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		memset(&pParam->chOperCode,0,20);
		memcpy(&pParam->chOperCode,pData+nReadPos,20);
		nReadPos += 20;

		memset(&pParam->chOperName,0,50);
		memcpy(&pParam->chOperName,pData+nReadPos,50);
		nReadPos += 50;

		memset(&pParam->chOpAddress,0,255);
		memcpy(&pParam->chOpAddress,pData+nReadPos,255);
		nReadPos += 255;

		memset(&pParam->chTransID,0,40);
		memcpy(&pParam->chTransID,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chPaySn,0,40);
		memcpy(&pParam->chPaySn,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chPayType,0,40);
		memcpy(&pParam->chPayType,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chRemark,0,255);
		memcpy(&pParam->chRemark,pData+nReadPos,255);
		nReadPos += 255;

		memset(&pParam->chBllType,0,5);
		memcpy(&pParam->chBllType,pData+nReadPos,5);
		nReadPos += 5;

		memset(Data_Buf,0,7);
		memset(&pParam->dtCreateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtCreateTime.nYear = (Data_Buf[0] << 8) |Data_Buf[1];
		pParam->dtCreateTime.nMonth = Data_Buf[2];
		pParam->dtCreateTime.nDay = Data_Buf[3];
		pParam->dtCreateTime.nHour = Data_Buf[4];
		pParam->dtCreateTime.nMinute = Data_Buf[5];
		pParam->dtCreateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		memset(Data_Buf,0,7);
		memset(&pParam->dtUpdateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->dtUpdateTime.nYear = (Data_Buf[0] << 8) |Data_Buf[1];
		pParam->dtUpdateTime.nMonth = Data_Buf[2];
		pParam->dtUpdateTime.nDay = Data_Buf[3];
		pParam->dtUpdateTime.nHour = Data_Buf[4];
		pParam->dtUpdateTime.nMinute = Data_Buf[5];
		pParam->dtUpdateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		if(nReadPos == Length){
			return CCMS_RETURN_OK;
		}
		else{
			return CCMS_ERRORMSG_FAIL;
		}
	}

}

//订单明细
SZTBTICKET_API  int  SZTBTicket_ParseOrderUploadTicket(const char* pData,int nDataLen,T_CCMS_TICKET_ORDERUPLOADTICKET* pParam)
{
	int nReadPos = 0;
	int Length = sizeof(T_CCMS_TICKET_ORDERUPLOADTICKET);
	if(pData == NULL || nDataLen <= 0)
	return CCMS_ERRORMSG_FAIL;

	if(nDataLen < Length){
		return CCMS_ERRORMSG_FAIL;
	}
	else{
		memset(pParam->chFServerSN,0,12);
		memcpy(pParam->chFServerSN,pData+nReadPos,12);
		nReadPos += 12;

		memset(&pParam->chGuid,0,40);
		memcpy(&pParam->chGuid,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chParentID,0,40);
		memcpy(&pParam->chParentID,pData+nReadPos,40);
		nReadPos += 40;

		memset(&pParam->chBarCode,0,10);
		memcpy(&pParam->chBarCode,pData+nReadPos,10);
		nReadPos += 10;

		memset(&pParam->chTicketNo,0,10);
		memcpy(&pParam->chTicketNo,pData+nReadPos,10);
		nReadPos += 10;

		memset(&pParam->chOrderNo,0,30);
		memcpy(&pParam->chOrderNo,pData+nReadPos,30);
		nReadPos += 30;

		UInt8 Data_Buf[7] = {0};
		memset(Data_Buf,0,7);
		memset(&pParam->ullCreateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->ullCreateTime.nYear = (Data_Buf[0] << 8) |Data_Buf[1];
		pParam->ullCreateTime.nMonth = Data_Buf[2];
		pParam->ullCreateTime.nDay = Data_Buf[3];
		pParam->ullCreateTime.nHour = Data_Buf[4];
		pParam->ullCreateTime.nMinute = Data_Buf[5];
		pParam->ullCreateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		memset(Data_Buf,0,7);
		memset(&pParam->ullUpdateTime,0,7);
		memcpy(Data_Buf,pData+nReadPos,7);
		pParam->ullUpdateTime.nYear = (Data_Buf[0] << 8) |Data_Buf[1];
		pParam->ullUpdateTime.nMonth = Data_Buf[2];
		pParam->ullUpdateTime.nDay = Data_Buf[3];
		pParam->ullUpdateTime.nHour = Data_Buf[4];
		pParam->ullUpdateTime.nMinute = Data_Buf[5];
		pParam->ullUpdateTime.nSecond = Data_Buf[6];
		nReadPos += 7;

		if(nReadPos == Length){
			return CCMS_RETURN_OK;
		}
		else{
			return CCMS_ERRORMSG_FAIL;
		}
	}

}

SZTBTICKET_API int SZTBTicket_ParseTicketResp(const char* pData, int nDataLen,T_CCMS_TICKET_RESP *pParam)
{
	int Length = sizeof(T_CCMS_TICKET_RESP);
	int nReadPos = 0;

	if(pData == NULL || nDataLen <= 0)
	return CCMS_ERRORMSG_FAIL;

	if(nDataLen < Length){
		return CCMS_ERRORMSG_FAIL;
	}
	else{
		memset(pParam->chFServerSN,0,12);
		memcpy(pParam->chFServerSN,pData+nReadPos,12);
		nReadPos += 12;

		memset(pParam->chGuid,0,40);
		memcpy(pParam->chGuid,pData+nReadPos,40);
		nReadPos += 40;

		if(nReadPos == Length){
			return CCMS_RETURN_OK;
		}
		else{
			return CCMS_ERRORMSG_FAIL;
		}
	}

}

//封包

SZTBTICKET_API int SZTBTicket_GetPackBufLen(int msgId)
{
    switch (msgId)
    {
    case CCMS_BASESCHEDULEDATA_MSG:
        return sizeof(T_CCMS_TICKET_BASESCHEDULE);
    case CCMS_BASESCHEDULE_DETAILDATA_MSG:
        return sizeof(T_CCMS_TICKET_BASESCHEDULE_DETAIL);
    case CCMS_BASESCHEDULE_PRICEDATA_MSG:
        return sizeof(T_CCMS_TICKET_BASESCHEDULEPRICE);
    case CCMS_SCHEDULEDATA_MSG:
        return sizeof(T_CCMS_TICKET_SCHEDULE);
    case CCMS_SCHEDULE_DETAILDATA_MSG:
        return sizeof(T_CCMS_TICKET_SCHEDULEDETAIL);
    case CCMS_SENDSCHEDULEDATA_MSG:
        return sizeof(T_CCMS_TICKET_SENDSCHEDULE);
    case CCMS_SENDSCHEDULE_DETAILDATA_MSG:
        return sizeof(T_CCMS_TICKET_SENDSCHEDULEDETAIL);
    case CCMS_ORDERUPLOADDATA_MSG:
        return sizeof(T_CCMS_TICKET_ORDERUPLOAD);
    case CCMS_ORDERUPLOAD_TICKETDATA_MSG:
        return sizeof(T_CCMS_TICKET_ORDERUPLOADTICKET);
    case CCMS_BASESCHEDULEDATA_RESPMSG:
    case CCMS_BASESCHEDULE_DETAILDATA_RESPMSG:
    case CCMS_BASESCHEDULE_PRICEDATA_RESPMSG:
    case CCMS_SCHEDULEDATA_RESPMSG:
    case CCMS_SCHEDULE_DETAILDATA_RESPMSG:
    case CCMS_SENDSCHEDULEDATA_RESPMSG:
    case CCMS_SENDSCHEDULE_DETAILDATA_RESPMSG:
    case CCMS_ORDERUPLOADDATA_RESPMSG:
    case CCMS_ORDERUPLOAD_TICKETDATA_RESPMSG:
        return sizeof(T_CCMS_TICKET_RESP);
    default:
        return -1;
    }
}


SZTBTICKET_API int SZTBTicket_PackTicketResp(
    const T_CCMS_TICKET_RESP *pParam, char* pData, int* nDataLen)
{
	assert(pData != NULL);
	int len = sizeof(T_CCMS_TICKET_RESP);
	char* temp = new char[len+1];
	int nPos_G = 0;
	memset(temp,0,len+1);

	memcpy(temp+nPos_G,&pParam->chFServerSN,12);
		nPos_G += 12;

	memcpy(temp+nPos_G,&pParam->chGuid,40);
		nPos_G += 40;

	if(nPos_G <= len){
			memcpy(pData,temp,nPos_G);
			delete[] temp;
			*nDataLen = nPos_G;
			return CCMS_RETURN_OK;
		}
	else{
	    delete[] temp;
		return CCMS_ERRORMSG_FAIL;
	}
}


// 班次信息
SZTBTICKET_API int SZTBTicket_PackBaseSchedule(const T_CCMS_TICKET_BASESCHEDULE *pParam, char* pData, int* nDataLen)
{
	//printf("enter Ticket_BaseSchedule_Pack\n");
	assert(pData != NULL);
	int len = sizeof(T_CCMS_TICKET_BASESCHEDULE);
	char *temp = new char[len+1];
	memset(temp,0,len+1);
	int nPos_G = 0;

	memcpy(temp+nPos_G,&pParam->chFServerSN,12);
		nPos_G += 12;

	memcpy(temp+nPos_G,&pParam->chGuid,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chGlobalCode,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chStationCode,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chStationName,80);
		nPos_G += 80;

	memcpy(temp+nPos_G,&pParam->chLocalCode,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chLineName,80);
		nPos_G += 80;

	memcpy(temp+nPos_G,&pParam->chTransType,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chLineKind,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chSchKind,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chSchType,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chSchMode,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chStartTime,4);
		nPos_G += 4;

	memcpy(temp+nPos_G,&pParam->chEndTime,4);
		nPos_G += 4;

	memcpy(temp+nPos_G,&pParam->nRotationInterval,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->chTime,4);
		nPos_G += 4;

	memcpy(temp+nPos_G,&pParam->chEndProvince,90);
		nPos_G += 90;

	memcpy(temp+nPos_G,&pParam->chEndCity,90);
		nPos_G += 90;

	memcpy(temp+nPos_G,&pParam->chEndCounty,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chEndTown,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chVillage,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chEndNodeCode,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chEndNodeName,50);
		nPos_G += 50;

	memcpy(temp+nPos_G,&pParam->chStartValidDate,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chEndValidDate,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chStatus,10);
		nPos_G += 10;

	PackDateTime(&pParam->dtUploadTime, temp + nPos_G);
	nPos_G += 7;

	PackDateTime(&pParam->dtCreateTime, temp + nPos_G);
	nPos_G += 7;

	PackDateTime(&pParam->dtUpdateTime, temp + nPos_G);
	nPos_G += 7;

	if(nPos_G <= len){
		memcpy(pData,temp,nPos_G);
		delete[] temp;
		*nDataLen = nPos_G;
		return CCMS_RETURN_OK;
	}
	else{
	    delete[] temp;
		return CCMS_ERRORMSG_FAIL;
	}

}

//班次信息--车辆信息
SZTBTICKET_API int SZTBTicket_PackBaseScheduleDetail(const T_CCMS_TICKET_BASESCHEDULE_DETAIL *pParam, char* pData, int* nDataLen)
{
	assert(pData != NULL);
	int len = sizeof(T_CCMS_TICKET_BASESCHEDULE_DETAIL);
	char *temp = new char[len+1];
	memset(temp,0,len+1);
	int nPos_G = 0;

	memcpy(temp+nPos_G,&pParam->chFServerSN,12);
		nPos_G += 12;

	memcpy(temp+nPos_G,&pParam->chGuid,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chParentID,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chStationCode,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chLocalCode,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chEnterpriseCode,15);
		nPos_G += 15;

	memcpy(temp+nPos_G,&pParam->chEnterpriseName,80);
		nPos_G += 80;

	memcpy(temp+nPos_G,&pParam->chBusCode,50);
		nPos_G += 50;

	memcpy(temp+nPos_G,&pParam->nSeatCount,1);
		nPos_G += 1;

	memcpy(temp+nPos_G,&pParam->chBusinessBus,1);
		nPos_G += 1;

	memcpy(temp+nPos_G,&pParam->chBusType,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chSeatType,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chBusLevel,40);
		nPos_G += 40;

	PackDateTime(&pParam->dtCreateTime, temp + nPos_G);
	nPos_G += 7;

	PackDateTime(&pParam->dtUpdateTime, temp + nPos_G);
    nPos_G += 7;

	if(nPos_G <= len){
		memcpy(pData,temp,nPos_G);
		delete[] temp;
		*nDataLen = nPos_G;
		return CCMS_RETURN_OK;
	}
	else{
	    delete[] temp;
		return CCMS_ERRORMSG_FAIL;
	}

}

//班次信息--票价信息
SZTBTICKET_API int SZTBTicket_PackBaseSchedulePrice(const T_CCMS_TICKET_BASESCHEDULEPRICE *pParam, char* pData, int* nDataLen)
{
	assert(pData != NULL);
	int len = sizeof(T_CCMS_TICKET_BASESCHEDULEPRICE);
	char *temp = new char[len+1];
	memset(temp,0,len+1);
	int nPos_G = 0;

	memcpy(temp+nPos_G,&pParam->chFServerSN,12);
		nPos_G += 12;

	memcpy(temp+nPos_G,&pParam->chGuid,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chParentID,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chStationCode,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chLocalCode,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chNodeName,100);
			nPos_G += 100;

	memcpy(temp+nPos_G,&pParam->chNodeCode,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chTravelTime,4);
		nPos_G += 4;

	memcpy(temp+nPos_G,&pParam->flMileage,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flTransPrice,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flSingle,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flSingleTripToll,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flBunkerSurcharge,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flStationFee,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flOtherFee,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flTransFee,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flUpperPrice,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flPrice,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flHalfprice,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flStdPrice,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flDisabilitySoldierPrice,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chValidityStart,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chValidityEnd,8);
		nPos_G += 8;

	PackDateTime(&pParam->dtCreateTime, temp + nPos_G);
	nPos_G += 7;

	PackDateTime(&pParam->dtUpdateTime, temp + nPos_G);
    nPos_G += 7;

	if(nPos_G <= len){
		memcpy(pData,temp,nPos_G);
		delete[] temp;
		*nDataLen = nPos_G;
		return CCMS_RETURN_OK;
	}
	else{
	    delete[] temp;
		return CCMS_ERRORMSG_FAIL;
	}

}


//发班班次
SZTBTICKET_API int SZTBTicket_PackSchedule(const T_CCMS_TICKET_SCHEDULE *pParam, char* pData, int* nDataLen)
{
	assert(pData != NULL);
	int nPos_G = 0;
	int len = sizeof(T_CCMS_TICKET_SCHEDULE);
	char *temp = new char[len+1];
	memset(temp,0,len+1);

	memcpy(temp+nPos_G,&pParam->chFServerSN,12);
		nPos_G += 12;

	memcpy(temp+nPos_G,&pParam->chGuid,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chGlobalCode,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chStationCode,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chStationName,80);
		nPos_G += 80;

	memcpy(temp+nPos_G,&pParam->chLocalCode,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chLineName,80);
		nPos_G += 80;

	memcpy(temp+nPos_G,&pParam->chTransType,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chLineKind,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chSchKind,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chSchType,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chSchMode,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chStartTime,4);
		nPos_G += 4;

	memcpy(temp+nPos_G,&pParam->chEndTime,4);
		nPos_G += 4;

	memcpy(temp+nPos_G,&pParam->nRotationInterval,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->chTime,4);
		nPos_G += 4;

	memcpy(temp+nPos_G,&pParam->chDate,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chEndProvince,90);
		nPos_G += 90;

	memcpy(temp+nPos_G,&pParam->chEndCity,90);
		nPos_G += 90;

	memcpy(temp+nPos_G,&pParam->chEndCounty,50);
		nPos_G += 50;

	memcpy(temp+nPos_G,&pParam->chEndTown,50);
		nPos_G += 50;

	memcpy(temp+nPos_G,&pParam->chVillage,50);
		nPos_G += 50;

	memcpy(temp+nPos_G,&pParam->chEndNodeCode,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chEndNodeName,50);
		nPos_G += 50;

	memcpy(temp+nPos_G,&pParam->chStatus,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->nSeatCount,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->nTicketSale,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->nTicketSell,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->nTicketCount,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->nFreeChildrenTicketSale,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->chEnterpriseCode,15);
		nPos_G += 15;

	memcpy(temp+nPos_G,&pParam->chEnterpriseName,80);
		nPos_G += 80;

	memcpy(temp+nPos_G,&pParam->chBusCode,50);
		nPos_G += 50;

	memcpy(temp+nPos_G,&pParam->bBusinessBus,1);
		nPos_G += 1;

	memcpy(temp+nPos_G,&pParam->chBusType,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chSeatType,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chBusLevel,40);
		nPos_G += 40;

	PackDateTime(&pParam->dtUploadTime, temp + nPos_G);
	nPos_G += 7;

	PackDateTime(&pParam->dtUpdateTime, temp + nPos_G);
	nPos_G += 7;

   if(nPos_G <= len){
		memcpy(pData,temp,nPos_G);
		delete[] temp;
		*nDataLen = nPos_G;
		return CCMS_RETURN_OK;
	}
   else{
       delete[] temp;
       return CCMS_ERRORMSG_FAIL;
   }


}

//发班班次--票价信息明细
SZTBTICKET_API int SZTBTicket_PackScheduleDetail(const T_CCMS_TICKET_SCHEDULEDETAIL *pParam, char* pData, int* nDataLen)
{
	assert(pData != NULL);
	int nPos_G = 0;
	int len = sizeof(T_CCMS_TICKET_SCHEDULEDETAIL);
	char *temp = new char[len+1];
	memset(temp,0,len+1);

	memcpy(temp+nPos_G,&pParam->chFServerSN,12);
		nPos_G += 12;

	memcpy(temp+nPos_G,&pParam->chGuid,40);
			nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chParentID,40);
			nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chStationCode,8);
			nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chLocalCode,20);
			nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chDate,8);
			nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chNodeCode,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chNodeName,100);
		nPos_G += 100;

	memcpy(temp+nPos_G,&pParam->flTravelTime,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flMileage,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flUpperPrice,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flPrice,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flHalfprice,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flStdPrice,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flDisabilitySoldierPrice,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->nFullTicketSale,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->nHalfTicketSale,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->nFreeTicketSale,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->nStdTicketSale,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->nDisabilitySoldierTicketSell,2);
		nPos_G += 2;

	PackDateTime(&pParam->dtCreateTime, temp + nPos_G);
	nPos_G += 7;

	PackDateTime(&pParam->dtUpdateTime, temp + nPos_G);
	nPos_G += 7;

   if(nPos_G <= len){
		memcpy(pData,temp,nPos_G);
		delete[] temp;
		*nDataLen = nPos_G;
		return CCMS_RETURN_OK;
	}
   else{
       delete[] temp;
       return CCMS_ERRORMSG_FAIL;
   }


}

//发班信息
SZTBTICKET_API int SZTBTicket_PackSendSchedule(const T_CCMS_TICKET_SENDSCHEDULE *pParam, char* pData, int* nDataLen)
{
	assert(pData != NULL);
	int nPos_G = 0;
	int len = sizeof(T_CCMS_TICKET_SENDSCHEDULE);
	char *temp = new char[len+1];;
	memset(temp,0,len+1);

	memcpy(temp+nPos_G,&pParam->chFServerSN,12);
		nPos_G += 12;

	memcpy(temp+nPos_G,&pParam->chGuid,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chGlobalCode,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chStationCode,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chStationName,80);
		nPos_G += 80;

	memcpy(temp+nPos_G,&pParam->chBusIC,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chBusCode,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chBusColor,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chEnterpriseCode,15);
		nPos_G += 15;

	memcpy(temp+nPos_G,&pParam->chEnterpriseName,80);
		nPos_G += 80;

	memcpy(temp+nPos_G,&pParam->chLocalCode,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chDate,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chTime,4);
		nPos_G += 4;

	memcpy(temp+nPos_G,&pParam->chInTime,4);
		nPos_G += 4;

	memcpy(temp+nPos_G,&pParam->chOutTime,4);
		nPos_G += 4;

	memcpy(temp+nPos_G,&pParam->chSafeCheck,6);
		nPos_G += 6;

	memcpy(temp+nPos_G,&pParam->nPassenger,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->nPassengerIn,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->nPassengerFee,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->nChild,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->nPassengerOut,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->chOper,20);
		nPos_G += 20;

	PackDateTime(&pParam->dtOpTime, temp + nPos_G);
	nPos_G += 7;

	PackDateTime(&pParam->dtUploadTime, temp + nPos_G);
	nPos_G += 7;

	memcpy(temp+nPos_G,&pParam->chIsSafeSuper,50);
		nPos_G += 50;

	memcpy(temp+nPos_G,&pParam->chRoadTransCode,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chSeatType,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chBusLevel,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chTechLevel,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chCarValid,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chMarkCarCode,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chLineName,80);
		nPos_G += 80;

	memcpy(temp+nPos_G,&pParam->chThroughLine,255);
		nPos_G += 255;

	memcpy(temp+nPos_G,&pParam->chNodes,255);
		nPos_G += 255;

	memcpy(temp+nPos_G,&pParam->chEndNodeCode,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chEndNodeName,50);
		nPos_G += 50;

	memcpy(temp+nPos_G,&pParam->chSchKind,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chSchType,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chSchMode,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chDrivingLicenseValid,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->bIsDanger,1);
		nPos_G += 1;

	memcpy(temp+nPos_G,&pParam->chDangerName,255);
		nPos_G += 255;

	memcpy(temp+nPos_G,&pParam->bIsSafetyBelt,1);
		nPos_G += 1;

	memcpy(temp+nPos_G,&pParam->bIsOverman,1);
		nPos_G += 1;

	memcpy(temp+nPos_G,&pParam->chDriver1,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chDriverCer1,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->bDriverValid1,1);
		nPos_G += 1;

	memcpy(temp+nPos_G,&pParam->chDriver2,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chDriverCer2,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->bDriverValid2,1);
		nPos_G += 1;

	memcpy(temp+nPos_G,&pParam->chDriver3,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chDriverCer3,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->bDriverValid3,1);
		nPos_G += 1;

	PackDateTime(&pParam->dtCreateTime, temp + nPos_G);
	nPos_G += 7;

	PackDateTime(&pParam->dtUpdateTime, temp + nPos_G);
	nPos_G += 7;

	 if(nPos_G <= len){
		memcpy(pData,temp,nPos_G);
		delete[] temp;
		*nDataLen = nPos_G;
		return CCMS_RETURN_OK;
	}
	 else{
	     delete[] temp;
	     return CCMS_ERRORMSG_FAIL;
	 }

}

//发班信息--到站明细
SZTBTICKET_API int SZTBTicket_PackSendScheduleDetail(const T_CCMS_TICKET_SENDSCHEDULEDETAIL *pParam, char* pData, int* nDataLen)
{
	assert(pData != NULL);
	int nPos_G = 0;
	int len = sizeof(T_CCMS_TICKET_SENDSCHEDULEDETAIL);
	char *temp = new char[len+1];;
	memset(temp,0,len+1);

	memcpy(temp+nPos_G,&pParam->chFServerSN,12);
		nPos_G += 12;

	memcpy(temp+nPos_G,&pParam->chGuid,40);
			nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chParentID,40);
			nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chStationCode,8);
			nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chDate,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chLocalCode,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chNodeCode,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chNodeName,50);
		nPos_G += 50;

	memcpy(temp+nPos_G,&pParam->nNodeNumber,2);
		nPos_G += 2;

	PackDateTime(&pParam->dtCreateTime, temp + nPos_G);
	nPos_G += 7;

	PackDateTime(&pParam->dtUpdateTime, temp + nPos_G);
	nPos_G += 7;

	 if(nPos_G <= len){
		memcpy(pData,temp,nPos_G);
		delete[] temp;
		*nDataLen = nPos_G;
		return CCMS_RETURN_OK;
	}
	 else{
	     delete[] temp;
	     return CCMS_ERRORMSG_FAIL;
	 }

}

//订单封包
SZTBTICKET_API int SZTBTicket_PackOrderUpload(const T_CCMS_TICKET_ORDERUPLOAD *pParam, char* pData, int* nDataLen)
{
	assert(pData != NULL);

	int nPos_G = 0;
	int len = sizeof(T_CCMS_TICKET_ORDERUPLOAD);
	char *temp = new char[len+1];
	memset(temp,0,len+1);

	memcpy(temp+nPos_G,&pParam->chFServerSN,12);
		nPos_G += 12;

	memcpy(temp+nPos_G,&pParam->chGuid,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chAgentCode,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chStationCode,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chStationName,80);
		nPos_G += 80;

	memcpy(temp+nPos_G,&pParam->chOrderNo,30);
		nPos_G += 30;

	memcpy(temp+nPos_G,&pParam->chScheduleNo,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->nTicketCount,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->flTicketAmount,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flAgentFee,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->flRefundFee,8);
		nPos_G += 8;

	memcpy(temp+nPos_G,&pParam->chBarCodes,255);
		nPos_G += 255;

	memcpy(temp+nPos_G,&pParam->chTicketNos,255);
		nPos_G += 255;

	memcpy(temp+nPos_G,&pParam->nRequestType,2);
		nPos_G += 2;

	memcpy(temp+nPos_G,&pParam->chTransStatus,15);
		nPos_G += 15;

	memcpy(temp+nPos_G,&pParam->nUploadMemberType,2);
		nPos_G += 2;

	PackDateTime(&pParam->dtOrderTime, temp + nPos_G);
	nPos_G += 7;

	memcpy(temp+nPos_G,&pParam->chOperCode,20);
		nPos_G += 20;

	memcpy(temp+nPos_G,&pParam->chOperName,50);
		nPos_G += 50;

	memcpy(temp+nPos_G,&pParam->chOpAddress,255);
		nPos_G += 255;

	memcpy(temp+nPos_G,&pParam->chTransID,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chPaySn,40);
	   nPos_G += 40;

   memcpy(temp+nPos_G,&pParam->chPayType,40);
		nPos_G += 40;

   memcpy(temp+nPos_G,&pParam->chRemark,255);
		nPos_G += 255;

   memcpy(temp+nPos_G,&pParam->chBllType,5);
		nPos_G += 5;

	PackDateTime(&pParam->dtCreateTime, temp + nPos_G);
	nPos_G += 7;

	PackDateTime(&pParam->dtUpdateTime, temp + nPos_G);
	nPos_G += 7;

	if(nPos_G <= len){
		memcpy(pData,temp,nPos_G);
		delete[] temp;
		*nDataLen = nPos_G;
		return CCMS_RETURN_OK;
	}
	else{
	    delete[] temp;
		return CCMS_ERRORMSG_FAIL;
	}

}

//订单明细
SZTBTICKET_API int SZTBTicket_PackOrderUploadTicket(const T_CCMS_TICKET_ORDERUPLOADTICKET *pParam, char* pData, int *nDataLen)
{
	assert(pData != NULL);

	int nPos_G = 0;
	int len = sizeof(T_CCMS_TICKET_ORDERUPLOADTICKET);
	char *temp = new char[len+1];;
	memset(temp,0,len+1);

	memcpy(temp+nPos_G,&pParam->chFServerSN,12);
		nPos_G += 12;

	memcpy(temp+nPos_G,&pParam->chGuid,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chParentID,40);
		nPos_G += 40;

	memcpy(temp+nPos_G,&pParam->chBarCode,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chTicketNo,10);
		nPos_G += 10;

	memcpy(temp+nPos_G,&pParam->chOrderNo,30);
		nPos_G += 30;

	PackDateTime(&pParam->ullCreateTime, temp + nPos_G);
	nPos_G += 7;

	PackDateTime(&pParam->ullUpdateTime, temp + nPos_G);
	nPos_G += 7;

	if(nPos_G <= len){
		memcpy(pData,temp,nPos_G);
		delete[] temp;
		*nDataLen = nPos_G;
		return CCMS_RETURN_OK;
	}
	else{
	    delete[] temp;
		return CCMS_ERRORMSG_FAIL;
	}
}

int PackDateTime(const DATETIME* dateTime, char* buf)
{
    UInt16 year = htons(dateTime->nYear);
    memcpy(buf, &year, 2);
    memcpy(buf + 2, &dateTime->nMonth, 1);
    memcpy(buf + 3, &dateTime->nDay, 1);
    memcpy(buf + 4, &dateTime->nHour, 1);
    memcpy(buf + 5, &dateTime->nMinute, 1);
    memcpy(buf + 6, &dateTime->nSecond, 1);
    return CCMS_RETURN_OK;
}
