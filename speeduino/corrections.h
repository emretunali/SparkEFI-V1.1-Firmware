/*
All functions in the gamma file return

*/
#ifndef CORRECTIONS_H
#define CORRECTIONS_H

void initialiseCorrections();

uint16_t correctionsFuel();
byte correctionWUE(); //Warmup enrichment
uint16_t correctionCranking(); //Cranking enrichment
byte correctionASE(); //After Start Enrichment
uint16_t correctionAccel(); //Acceleration Enrichment
byte correctionFloodClear(); //Check for flood clear on cranking
byte correctionAFRClosedLoop(); //Closed loop AFR adjustment
byte correctionFlex(); //Flex fuel adjustment
byte correctionFuelTemp(); //Fuel temp correction
byte correctionBatVoltage(); //Battery voltage correction
byte correctionIATDensity(); //Inlet temp density correction
byte correctionBaro(); //Barometric pressure correction
byte correctionLaunch(); //Launch control correction
bool correctionDFCO(); //Decelleration fuel cutoff


int8_t correctionsIgn(int8_t advance);
int8_t correctionFixedTiming(int8_t);
int8_t correctionCrankingFixedTiming(int8_t);
int8_t correctionFlexTiming(int8_t);
int8_t correctionWMITiming(int8_t);
int8_t correctionIATretard(int8_t);
int8_t correctionCLTadvance(int8_t);
int8_t correctionIdleAdvance(int8_t);
int8_t correctionSoftRevLimit(int8_t);
int8_t correctionNitrous(int8_t);
int8_t correctionSoftLaunch(int8_t);
int8_t correctionSoftFlatShift(int8_t);
int8_t correctionKnock(int8_t);

uint16_t correctionsDwell(uint16_t dwell);

extern int MAP_rateOfChange;
extern int TPS_rateOfChange;
extern byte activateMAPDOT; //The mapDOT value seen when the MAE was activated. 
extern byte activateTPSDOT; //The tpsDOT value seen when the MAE was activated. 

extern uint16_t AFRnextCycle;
extern unsigned long knockStartTime;
extern byte lastKnockCount;
extern int16_t knockWindowMin; //The current minimum crank angle for a knock pulse to be valid
extern int16_t knockWindowMax;//The current maximum crank angle for a knock pulse to be valid
extern uint16_t aseTaperStart;
extern uint16_t dfcoStart;
extern uint16_t idleAdvStart;

#endif // CORRECTIONS_H
