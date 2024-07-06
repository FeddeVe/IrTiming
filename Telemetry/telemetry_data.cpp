#include "telemetry_data.h"

Telemetry_Data::Telemetry_Data(QObject *parent) : QObject(parent)
{
  this->isset = false;
  this->SessionTime = new ir_tel_var(this, "SessionTime");
  this->all_vars.push_back(this->SessionTime);
  this->SessionTick = new ir_tel_var(this, "SessionTick");
  this->all_vars.push_back(this->SessionTick);
  this->SessionNum = new ir_tel_var(this, "SessionNum");
  this->all_vars.push_back(this->SessionNum);
  this->SessionState = new ir_tel_var(this, "SessionState");
  this->all_vars.push_back(this->SessionState);
  this->SessionUniqueID = new ir_tel_var(this, "SessionUniqueID");
  this->all_vars.push_back(this->SessionUniqueID);
  this->SessionFlags = new ir_tel_var(this, "SessionFlags");
  this->all_vars.push_back(this->SessionFlags);
  this->SessionTimeRemain = new ir_tel_var(this, "SessionTimeRemain");
  this->all_vars.push_back(this->SessionTimeRemain);
  this->SessionLapsRemain = new ir_tel_var(this, "SessionLapsRemain");
  this->all_vars.push_back(this->SessionLapsRemain);
  this->SessionLapsRemainEx = new ir_tel_var(this, "SessionLapsRemainEx");
  this->all_vars.push_back(this->SessionLapsRemainEx);
  this->SessionTimeOfDay = new ir_tel_var(this, "SessionTimeOfDay");
  this->all_vars.push_back(this->SessionTimeOfDay);
  this->DriverMarker = new ir_tel_var(this, "DriverMarker");
  this->all_vars.push_back(this->DriverMarker);
  this->PushToPass = new ir_tel_var(this, "PushToPass");
  this->all_vars.push_back(this->PushToPass);
  this->ManualBoost = new ir_tel_var(this, "ManualBoost");
  this->all_vars.push_back(this->ManualBoost);
  this->ManualNoBoost = new ir_tel_var(this, "ManualNoBoost");
  this->all_vars.push_back(this->ManualNoBoost);
  this->IsOnTrack = new ir_tel_var(this, "IsOnTrack");
  this->all_vars.push_back(this->IsOnTrack);
  this->FrameRate = new ir_tel_var(this, "FrameRate");
  this->all_vars.push_back(this->FrameRate);
  this->CpuUsageBG = new ir_tel_var(this, "CpuUsageBG");
  this->all_vars.push_back(this->CpuUsageBG);
  this->PlayerCarPosition = new ir_tel_var(this, "PlayerCarPosition");
  this->all_vars.push_back(this->PlayerCarPosition);
  this->PlayerCarClassPosition = new ir_tel_var(this, "PlayerCarClassPosition");
  this->all_vars.push_back(this->PlayerCarClassPosition);
  this->PlayerTrackSurface = new ir_tel_var(this, "PlayerTrackSurface");
  this->all_vars.push_back(this->PlayerTrackSurface);
  this->PlayerTrackSurfaceMaterial = new ir_tel_var(this, "PlayerTrackSurfaceMaterial");
  this->all_vars.push_back(this->PlayerTrackSurfaceMaterial);
  this->PlayerCarIdx = new ir_tel_var(this, "PlayerCarIdx");
  this->all_vars.push_back(this->PlayerCarIdx);
  this->PlayerCarTeamIncidentCount = new ir_tel_var(this, "PlayerCarTeamIncidentCount");
  this->all_vars.push_back(this->PlayerCarTeamIncidentCount);
  this->PlayerCarMyIncidentCount = new ir_tel_var(this, "PlayerCarMyIncidentCount");
  this->all_vars.push_back(this->PlayerCarMyIncidentCount);
  this->PlayerCarDriverIncidentCount = new ir_tel_var(this, "PlayerCarDriverIncidentCount");
  this->all_vars.push_back(this->PlayerCarDriverIncidentCount);
  this->PlayerCarWeightPenalty = new ir_tel_var(this, "PlayerCarWeightPenalty");
  this->all_vars.push_back(this->PlayerCarWeightPenalty);
  this->PlayerCarPowerAdjust = new ir_tel_var(this, "PlayerCarPowerAdjust");
  this->all_vars.push_back(this->PlayerCarPowerAdjust);
  this->PlayerCarDryTireSetLimit = new ir_tel_var(this, "PlayerCarDryTireSetLimit");
  this->all_vars.push_back(this->PlayerCarDryTireSetLimit);
  this->PlayerCarTowTime = new ir_tel_var(this, "PlayerCarTowTime");
  this->all_vars.push_back(this->PlayerCarTowTime);
  this->PlayerCarInPitStall = new ir_tel_var(this, "PlayerCarInPitStall");
  this->all_vars.push_back(this->PlayerCarInPitStall);
  this->PlayerCarPitSvStatus = new ir_tel_var(this, "PlayerCarPitSvStatus");
  this->all_vars.push_back(this->PlayerCarPitSvStatus);
  this->PaceMode = new ir_tel_var(this, "PaceMode");
  this->all_vars.push_back(this->PaceMode);
  this->OnPitRoad = new ir_tel_var(this, "OnPitRoad");
  this->all_vars.push_back(this->OnPitRoad);
  this->SteeringWheelAngle = new ir_tel_var(this, "SteeringWheelAngle");
  this->all_vars.push_back(this->SteeringWheelAngle);
  this->Throttle = new ir_tel_var(this, "Throttle");
  this->all_vars.push_back(this->Throttle);
  this->Brake = new ir_tel_var(this, "Brake");
  this->all_vars.push_back(this->Brake);
  this->Clutch = new ir_tel_var(this, "Clutch");
  this->all_vars.push_back(this->Clutch);
  this->Gear = new ir_tel_var(this, "Gear");
  this->all_vars.push_back(this->Gear);
  this->RPM = new ir_tel_var(this, "RPM");
  this->all_vars.push_back(this->RPM);
  this->Lap = new ir_tel_var(this, "Lap");
  this->all_vars.push_back(this->Lap);
  this->LapCompleted = new ir_tel_var(this, "LapCompleted");
  this->all_vars.push_back(this->LapCompleted);
  this->LapDist = new ir_tel_var(this, "LapDist");
  this->all_vars.push_back(this->LapDist);
  this->LapDistPct = new ir_tel_var(this, "LapDistPct");
  this->all_vars.push_back(this->LapDistPct);
  this->LapBestLap = new ir_tel_var(this, "LapBestLap");
  this->all_vars.push_back(this->LapBestLap);
  this->LapBestLapTime = new ir_tel_var(this, "LapBestLapTime");
  this->all_vars.push_back(this->LapBestLapTime);
  this->LapLastLapTime = new ir_tel_var(this, "LapLastLapTime");
  this->all_vars.push_back(this->LapLastLapTime);
  this->LapCurrentLapTime = new ir_tel_var(this, "LapCurrentLapTime");
  this->all_vars.push_back(this->LapCurrentLapTime);
  this->LapLasNLapSeq = new ir_tel_var(this, "LapLasNLapSeq");
  this->all_vars.push_back(this->LapLasNLapSeq);
  this->LapLastNLapTime = new ir_tel_var(this, "LapLastNLapTime");
  this->all_vars.push_back(this->LapLastNLapTime);
  this->LapBestNLapLap = new ir_tel_var(this, "LapBestNLapLap");
  this->all_vars.push_back(this->LapBestNLapLap);
  this->LapBestNLapTime = new ir_tel_var(this, "LapBestNLapTime");
  this->all_vars.push_back(this->LapBestNLapTime);
  this->LapDeltaToBestLap = new ir_tel_var(this, "LapDeltaToBestLap");
  this->all_vars.push_back(this->LapDeltaToBestLap);
  this->LapDeltaToBestLap_DD = new ir_tel_var(this, "LapDeltaToBestLap_DD");
  this->all_vars.push_back(this->LapDeltaToBestLap_DD);
  this->LapDeltaToBestLap_OK = new ir_tel_var(this, "LapDeltaToBestLap_OK");
  this->all_vars.push_back(this->LapDeltaToBestLap_OK);
  this->LapDeltaToOptimalLap = new ir_tel_var(this, "LapDeltaToOptimalLap");
  this->all_vars.push_back(this->LapDeltaToOptimalLap);
  this->LapDeltaToOptimalLap_DD = new ir_tel_var(this, "LapDeltaToOptimalLap_DD");
  this->all_vars.push_back(this->LapDeltaToOptimalLap_DD);
  this->LapDeltaToOptimalLap_OK = new ir_tel_var(this, "LapDeltaToOptimalLap_OK");
  this->all_vars.push_back(this->LapDeltaToOptimalLap_OK);
  this->LapDeltaToSessionBestLap = new ir_tel_var(this, "LapDeltaToSessionBestLap");
  this->all_vars.push_back(this->LapDeltaToSessionBestLap);
  this->LapDeltaToSessionBestLap_DD = new ir_tel_var(this, "LapDeltaToSessionBestLap_DD");
  this->all_vars.push_back(this->LapDeltaToSessionBestLap_DD);
  this->LapDeltaToSessionBestLap_OK = new ir_tel_var(this, "LapDeltaToSessionBestLap_OK");
  this->all_vars.push_back(this->LapDeltaToSessionBestLap_OK);
  this->LapDeltaToSessionOptimalLap = new ir_tel_var(this, "LapDeltaToSessionOptimalLap");
  this->all_vars.push_back(this->LapDeltaToSessionOptimalLap);
  this->LapDeltaToSessionOptimalLap_DD = new ir_tel_var(this, "LapDeltaToSessionOptimalLap_DD");
  this->all_vars.push_back(this->LapDeltaToSessionOptimalLap_DD);
  this->LapDeltaToSessionOptimalLap_OK = new ir_tel_var(this, "LapDeltaToSessionOptimalLap_OK");
  this->all_vars.push_back(this->LapDeltaToSessionOptimalLap_OK);
  this->LapDeltaToSessionLastlLap = new ir_tel_var(this, "LapDeltaToSessionLastlLap");
  this->all_vars.push_back(this->LapDeltaToSessionLastlLap);
  this->LapDeltaToSessionLastlLap_DD = new ir_tel_var(this, "LapDeltaToSessionLastlLap_DD");
  this->all_vars.push_back(this->LapDeltaToSessionLastlLap_DD);
  this->LapDeltaToSessionLastlLap_OK = new ir_tel_var(this, "LapDeltaToSessionLastlLap_OK");
  this->all_vars.push_back(this->LapDeltaToSessionLastlLap_OK);
  this->Speed = new ir_tel_var(this, "Speed");
  this->all_vars.push_back(this->Speed);
  this->Yaw = new ir_tel_var(this, "Yaw");
  this->all_vars.push_back(this->Yaw);
  this->YawNorth = new ir_tel_var(this, "YawNorth");
  this->all_vars.push_back(this->YawNorth);
  this->Pitch = new ir_tel_var(this, "Pitch");
  this->all_vars.push_back(this->Pitch);
  this->Roll = new ir_tel_var(this, "Roll");
  this->all_vars.push_back(this->Roll);
  this->EnterExitReset = new ir_tel_var(this, "EnterExitReset");
  this->all_vars.push_back(this->EnterExitReset);
  this->Lat = new ir_tel_var(this, "Lat");
  this->all_vars.push_back(this->Lat);
  this->Lon = new ir_tel_var(this, "Lon");
  this->all_vars.push_back(this->Lon);
  this->Alt = new ir_tel_var(this, "Alt");
  this->all_vars.push_back(this->Alt);
  this->TrackTemp = new ir_tel_var(this, "TrackTemp");
  this->all_vars.push_back(this->TrackTemp);
  this->TrackTempCrew = new ir_tel_var(this, "TrackTempCrew");
  this->all_vars.push_back(this->TrackTempCrew);
  this->AirTemp = new ir_tel_var(this, "AirTemp");
  this->all_vars.push_back(this->AirTemp);
  this->WeatherType = new ir_tel_var(this, "WeatherType");
  this->all_vars.push_back(this->WeatherType);
  this->Skies = new ir_tel_var(this, "Skies");
  this->all_vars.push_back(this->Skies);
  this->AirDensity = new ir_tel_var(this, "AirDensity");
  this->all_vars.push_back(this->AirDensity);
  this->AirPressure = new ir_tel_var(this, "AirPressure");
  this->all_vars.push_back(this->AirPressure);
  this->WindVel = new ir_tel_var(this, "WindVel");
  this->all_vars.push_back(this->WindVel);
  this->WindDir = new ir_tel_var(this, "WindDir");
  this->all_vars.push_back(this->WindDir);
  this->RelativeHumidity = new ir_tel_var(this, "RelativeHumidity");
  this->all_vars.push_back(this->RelativeHumidity);
  this->FogLevel = new ir_tel_var(this, "FogLevel");
  this->all_vars.push_back(this->FogLevel);
  this->PitsOpen = new ir_tel_var(this, "PitsOpen");
  this->all_vars.push_back(this->PitsOpen);
  this->PitRepairLeft = new ir_tel_var(this, "PitRepairLeft");
  this->all_vars.push_back(this->PitRepairLeft);
  this->PitOptRepairLeft = new ir_tel_var(this, "PitOptRepairLeft");
  this->all_vars.push_back(this->PitOptRepairLeft);
  this->PitstopActive = new ir_tel_var(this, "PitstopActive");
  this->all_vars.push_back(this->PitstopActive);
  this->FastRepairUsed = new ir_tel_var(this, "FastRepairUsed");
  this->all_vars.push_back(this->FastRepairUsed);
  this->FastRepairAvailable = new ir_tel_var(this, "FastRepairAvailable");
  this->all_vars.push_back(this->FastRepairAvailable);
  this->LFTiresUsed = new ir_tel_var(this, "LFTiresUsed");
  this->all_vars.push_back(this->LFTiresUsed);
  this->RFTiresUsed = new ir_tel_var(this, "RFTiresUsed");
  this->all_vars.push_back(this->RFTiresUsed);
  this->LRTiresUsed = new ir_tel_var(this, "LRTiresUsed");
  this->all_vars.push_back(this->LRTiresUsed);
  this->RRTiresUsed = new ir_tel_var(this, "RRTiresUsed");
  this->all_vars.push_back(this->RRTiresUsed);
  this->LeftTireSetsUsed = new ir_tel_var(this, "LeftTireSetsUsed");
  this->all_vars.push_back(this->LeftTireSetsUsed);
  this->RightTireSetsUsed = new ir_tel_var(this, "RightTireSetsUsed");
  this->all_vars.push_back(this->RightTireSetsUsed);
  this->FrontTireSetsUsed = new ir_tel_var(this, "FrontTireSetsUsed");
  this->all_vars.push_back(this->FrontTireSetsUsed);
  this->RearTireSetsUsed = new ir_tel_var(this, "RearTireSetsUsed");
  this->all_vars.push_back(this->RearTireSetsUsed);
  this->TireSetsUsed = new ir_tel_var(this, "TireSetsUsed");
  this->all_vars.push_back(this->TireSetsUsed);
  this->LFTiresAvailable = new ir_tel_var(this, "LFTiresAvailable");
  this->all_vars.push_back(this->LFTiresAvailable);
  this->RFTiresAvailable = new ir_tel_var(this, "RFTiresAvailable");
  this->all_vars.push_back(this->RFTiresAvailable);
  this->LRTiresAvailable = new ir_tel_var(this, "LRTiresAvailable");
  this->all_vars.push_back(this->LRTiresAvailable);
  this->RRTiresAvailable = new ir_tel_var(this, "RRTiresAvailable");
  this->all_vars.push_back(this->RRTiresAvailable);
  this->LeftTireSetsAvailable = new ir_tel_var(this, "LeftTireSetsAvailable");
  this->all_vars.push_back(this->LeftTireSetsAvailable);
  this->RightTireSetsAvailable = new ir_tel_var(this, "RightTireSetsAvailable");
  this->all_vars.push_back(this->RightTireSetsAvailable);
  this->FrontTireSetsAvailable = new ir_tel_var(this, "FrontTireSetsAvailable");
  this->all_vars.push_back(this->FrontTireSetsAvailable);
  this->RearTireSetsAvailable = new ir_tel_var(this, "RearTireSetsAvailable");
  this->all_vars.push_back(this->RearTireSetsAvailable);
  this->TireSetsAvailable = new ir_tel_var(this, "TireSetsAvailable");
  this->all_vars.push_back(this->TireSetsAvailable);
  this->IsOnTrackCar = new ir_tel_var(this, "IsOnTrackCar");
  this->all_vars.push_back(this->IsOnTrackCar);
  this->SteeringWheelPctTorque = new ir_tel_var(this, "SteeringWheelPctTorque");
  this->all_vars.push_back(this->SteeringWheelPctTorque);
  this->SteeringWheelPctTorqueSign = new ir_tel_var(this, "SteeringWheelPctTorqueSign");
  this->all_vars.push_back(this->SteeringWheelPctTorqueSign);
  this->SteeringWheelPctTorqueSignStops = new ir_tel_var(this, "SteeringWheelPctTorqueSignStops");
  this->all_vars.push_back(this->SteeringWheelPctTorqueSignStops);
  this->SteeringWheelPctDamper = new ir_tel_var(this, "SteeringWheelPctDamper");
  this->all_vars.push_back(this->SteeringWheelPctDamper);
  this->SteeringWheelAngleMax = new ir_tel_var(this, "SteeringWheelAngleMax");
  this->all_vars.push_back(this->SteeringWheelAngleMax);
  this->ShiftIndicatorPct = new ir_tel_var(this, "ShiftIndicatorPct");
  this->all_vars.push_back(this->ShiftIndicatorPct);
  this->ShiftPowerPct = new ir_tel_var(this, "ShiftPowerPct");
  this->all_vars.push_back(this->ShiftPowerPct);
  this->ShiftGrindRPM = new ir_tel_var(this, "ShiftGrindRPM");
  this->all_vars.push_back(this->ShiftGrindRPM);
  this->ThrottleRaw = new ir_tel_var(this, "ThrottleRaw");
  this->all_vars.push_back(this->ThrottleRaw);
  this->BrakeRaw = new ir_tel_var(this, "BrakeRaw");
  this->all_vars.push_back(this->BrakeRaw);
  this->HandbrakeRaw = new ir_tel_var(this, "HandbrakeRaw");
  this->all_vars.push_back(this->HandbrakeRaw);
  this->EngineWarnings = new ir_tel_var(this, "EngineWarnings");
  this->all_vars.push_back(this->EngineWarnings);
  this->FuelLevel = new ir_tel_var(this, "FuelLevel");
  this->all_vars.push_back(this->FuelLevel);
  this->FuelLevelPct = new ir_tel_var(this, "FuelLevelPct");
  this->all_vars.push_back(this->FuelLevelPct);
  this->PitSvFlags = new ir_tel_var(this, "PitSvFlags");
  this->all_vars.push_back(this->PitSvFlags);
  this->PitSvLFP = new ir_tel_var(this, "PitSvLFP");
  this->all_vars.push_back(this->PitSvLFP);
  this->PitSvRFP = new ir_tel_var(this, "PitSvRFP");
  this->all_vars.push_back(this->PitSvRFP);
  this->PitSvLRP = new ir_tel_var(this, "PitSvLRP");
  this->all_vars.push_back(this->PitSvLRP);
  this->PitSvRRP = new ir_tel_var(this, "PitSvRRP");
  this->all_vars.push_back(this->PitSvRRP);
  this->PitSvFuel = new ir_tel_var(this, "PitSvFuel");
  this->all_vars.push_back(this->PitSvFuel);
  this->TireLF_RumblePitch = new ir_tel_var(this, "TireLF_RumblePitch");
  this->all_vars.push_back(this->TireLF_RumblePitch);
  this->TireRF_RumblePitch = new ir_tel_var(this, "TireRF_RumblePitch");
  this->all_vars.push_back(this->TireRF_RumblePitch);
  this->TireLR_RumblePitch = new ir_tel_var(this, "TireLR_RumblePitch");
  this->all_vars.push_back(this->TireLR_RumblePitch);
  this->TireRR_RumblePitch = new ir_tel_var(this, "TireRR_RumblePitch");
  this->all_vars.push_back(this->TireRR_RumblePitch);
  this->SteeringWheelTorque = new ir_tel_var(this, "SteeringWheelTorque");
  this->all_vars.push_back(this->SteeringWheelTorque);
  this->VelocityZ = new ir_tel_var(this, "VelocityZ");
  this->all_vars.push_back(this->VelocityZ);
  this->VelocityY = new ir_tel_var(this, "VelocityY");
  this->all_vars.push_back(this->VelocityY);
  this->VelocityX = new ir_tel_var(this, "VelocityX");
  this->all_vars.push_back(this->VelocityX);
  this->YawRate = new ir_tel_var(this, "YawRate");
  this->all_vars.push_back(this->YawRate);
  this->PitchRate = new ir_tel_var(this, "PitchRate");
  this->all_vars.push_back(this->PitchRate);
  this->RollRate = new ir_tel_var(this, "RollRate");
  this->all_vars.push_back(this->RollRate);
  this->VertAccel = new ir_tel_var(this, "VertAccel");
  this->all_vars.push_back(this->VertAccel);
  this->LatAccel = new ir_tel_var(this, "LatAccel");
  this->all_vars.push_back(this->LatAccel);
  this->LongAccel = new ir_tel_var(this, "LongAccel");
  this->all_vars.push_back(this->LongAccel);
  this->dcStarter = new ir_tel_var(this, "dcStarter");
  this->all_vars.push_back(this->dcStarter);
  this->dcPitSpeedLimiterToggle = new ir_tel_var(this, "dcPitSpeedLimiterToggle");
  this->all_vars.push_back(this->dcPitSpeedLimiterToggle);
  this->dcTractionControlToggle = new ir_tel_var(this, "dcTractionControlToggle");
  this->all_vars.push_back(this->dcTractionControlToggle);
  this->dcHeadlightFlash = new ir_tel_var(this, "dcHeadlightFlash");
  this->all_vars.push_back(this->dcHeadlightFlash);
  this->dcTearOffVisor = new ir_tel_var(this, "dcTearOffVisor");
  this->all_vars.push_back(this->dcTearOffVisor);
  this->dpRFTireChange = new ir_tel_var(this, "dpRFTireChange");
  this->all_vars.push_back(this->dpRFTireChange);
  this->dpLFTireChange = new ir_tel_var(this, "dpLFTireChange");
  this->all_vars.push_back(this->dpLFTireChange);
  this->dpRRTireChange = new ir_tel_var(this, "dpRRTireChange");
  this->all_vars.push_back(this->dpRRTireChange);
  this->dpLRTireChange = new ir_tel_var(this, "dpLRTireChange");
  this->all_vars.push_back(this->dpLRTireChange);
  this->dpFuelFill = new ir_tel_var(this, "dpFuelFill");
  this->all_vars.push_back(this->dpFuelFill);
  this->dpFuelAddKg = new ir_tel_var(this, "dpFuelAddKg");
  this->all_vars.push_back(this->dpFuelAddKg);
  this->dpFastRepair = new ir_tel_var(this, "dpFastRepair");
  this->all_vars.push_back(this->dpFastRepair);
  this->dcBrakeBias = new ir_tel_var(this, "dcBrakeBias");
  this->all_vars.push_back(this->dcBrakeBias);
  this->dpLFTireColdPress = new ir_tel_var(this, "dpLFTireColdPress");
  this->all_vars.push_back(this->dpLFTireColdPress);
  this->dpRFTireColdPress = new ir_tel_var(this, "dpRFTireColdPress");
  this->all_vars.push_back(this->dpRFTireColdPress);
  this->dpLRTireColdPress = new ir_tel_var(this, "dpLRTireColdPress");
  this->all_vars.push_back(this->dpLRTireColdPress);
  this->dpRRTireColdPress = new ir_tel_var(this, "dpRRTireColdPress");
  this->all_vars.push_back(this->dpRRTireColdPress);
  this->dcEnginePower = new ir_tel_var(this, "dcEnginePower");
  this->all_vars.push_back(this->dcEnginePower);
  this->dpPowerSteering = new ir_tel_var(this, "dpPowerSteering");
  this->all_vars.push_back(this->dpPowerSteering);
  this->dcTractionControl = new ir_tel_var(this, "dcTractionControl");
  this->all_vars.push_back(this->dcTractionControl);
  this->dcTractionControl2 = new ir_tel_var(this, "dcTractionControl2");
  this->all_vars.push_back(this->dcTractionControl2);
  this->WaterTemp = new ir_tel_var(this, "WaterTemp");
  this->all_vars.push_back(this->WaterTemp);
  this->WaterLevel = new ir_tel_var(this, "WaterLevel");
  this->all_vars.push_back(this->WaterLevel);
  this->FuelPress = new ir_tel_var(this, "FuelPress");
  this->all_vars.push_back(this->FuelPress);
  this->FuelUsePerHour = new ir_tel_var(this, "FuelUsePerHour");
  this->all_vars.push_back(this->FuelUsePerHour);
  this->OilTemp = new ir_tel_var(this, "OilTemp");
  this->all_vars.push_back(this->OilTemp);
  this->OilPress = new ir_tel_var(this, "OilPress");
  this->all_vars.push_back(this->OilPress);
  this->OilLevel = new ir_tel_var(this, "OilLevel");
  this->all_vars.push_back(this->OilLevel);
  this->Voltage = new ir_tel_var(this, "Voltage");
  this->all_vars.push_back(this->Voltage);
  this->ManifoldPress = new ir_tel_var(this, "ManifoldPress");
  this->all_vars.push_back(this->ManifoldPress);
  this->RRspeed = new ir_tel_var(this, "RRspeed");
  this->all_vars.push_back(this->RRspeed);
  this->RRpressure = new ir_tel_var(this, "RRpressure");
  this->all_vars.push_back(this->RRpressure);
  this->RRcoldPressure = new ir_tel_var(this, "RRcoldPressure");
  this->all_vars.push_back(this->RRcoldPressure);
  this->RRtempL = new ir_tel_var(this, "RRtempL");
  this->all_vars.push_back(this->RRtempL);
  this->RRtempM = new ir_tel_var(this, "RRtempM");
  this->all_vars.push_back(this->RRtempM);
  this->RRtempR = new ir_tel_var(this, "RRtempR");
  this->all_vars.push_back(this->RRtempR);
  this->RRtempCL = new ir_tel_var(this, "RRtempCL");
  this->all_vars.push_back(this->RRtempCL);
  this->RRtempCM = new ir_tel_var(this, "RRtempCM");
  this->all_vars.push_back(this->RRtempCM);
  this->RRtempCR = new ir_tel_var(this, "RRtempCR");
  this->all_vars.push_back(this->RRtempCR);
  this->RRwearL = new ir_tel_var(this, "RRwearL");
  this->all_vars.push_back(this->RRwearL);
  this->RRwearM = new ir_tel_var(this, "RRwearM");
  this->all_vars.push_back(this->RRwearM);
  this->RRwearR = new ir_tel_var(this, "RRwearR");
  this->all_vars.push_back(this->RRwearR);
  this->LRspeed = new ir_tel_var(this, "LRspeed");
  this->all_vars.push_back(this->LRspeed);
  this->LRpressure = new ir_tel_var(this, "LRpressure");
  this->all_vars.push_back(this->LRpressure);
  this->LRcoldPressure = new ir_tel_var(this, "LRcoldPressure");
  this->all_vars.push_back(this->LRcoldPressure);
  this->LRtempL = new ir_tel_var(this, "LRtempL");
  this->all_vars.push_back(this->LRtempL);
  this->LRtempM = new ir_tel_var(this, "LRtempM");
  this->all_vars.push_back(this->LRtempM);
  this->LRtempR = new ir_tel_var(this, "LRtempR");
  this->all_vars.push_back(this->LRtempR);
  this->LRtempCL = new ir_tel_var(this, "LRtempCL");
  this->all_vars.push_back(this->LRtempCL);
  this->LRtempCM = new ir_tel_var(this, "LRtempCM");
  this->all_vars.push_back(this->LRtempCM);
  this->LRtempCR = new ir_tel_var(this, "LRtempCR");
  this->all_vars.push_back(this->LRtempCR);
  this->LRwearL = new ir_tel_var(this, "LRwearL");
  this->all_vars.push_back(this->LRwearL);
  this->LRwearM = new ir_tel_var(this, "LRwearM");
  this->all_vars.push_back(this->LRwearM);
  this->LRwearR = new ir_tel_var(this, "LRwearR");
  this->all_vars.push_back(this->LRwearR);
  this->RFspeed = new ir_tel_var(this, "RFspeed");
  this->all_vars.push_back(this->RFspeed);
  this->RFpressure = new ir_tel_var(this, "RFpressure");
  this->all_vars.push_back(this->RFpressure);
  this->RFcoldPressure = new ir_tel_var(this, "RFcoldPressure");
  this->all_vars.push_back(this->RFcoldPressure);
  this->RFtempL = new ir_tel_var(this, "RFtempL");
  this->all_vars.push_back(this->RFtempL);
  this->RFtempM = new ir_tel_var(this, "RFtempM");
  this->all_vars.push_back(this->RFtempM);
  this->RFtempR = new ir_tel_var(this, "RFtempR");
  this->all_vars.push_back(this->RFtempR);
  this->RFtempCL = new ir_tel_var(this, "RFtempCL");
  this->all_vars.push_back(this->RFtempCL);
  this->RFtempCM = new ir_tel_var(this, "RFtempCM");
  this->all_vars.push_back(this->RFtempCM);
  this->RFtempCR = new ir_tel_var(this, "RFtempCR");
  this->all_vars.push_back(this->RFtempCR);
  this->RFwearL = new ir_tel_var(this, "RFwearL");
  this->all_vars.push_back(this->RFwearL);
  this->RFwearM = new ir_tel_var(this, "RFwearM");
  this->all_vars.push_back(this->RFwearM);
  this->RFwearR = new ir_tel_var(this, "RFwearR");
  this->all_vars.push_back(this->RFwearR);
  this->LFspeed = new ir_tel_var(this, "LFspeed");
  this->all_vars.push_back(this->LFspeed);
  this->LFpressure = new ir_tel_var(this, "LFpressure");
  this->all_vars.push_back(this->LFpressure);
  this->LFcoldPressure = new ir_tel_var(this, "LFcoldPressure");
  this->all_vars.push_back(this->LFcoldPressure);
  this->LFtempL = new ir_tel_var(this, "LFtempL");
  this->all_vars.push_back(this->LFtempL);
  this->LFtempM = new ir_tel_var(this, "LFtempM");
  this->all_vars.push_back(this->LFtempM);
  this->LFtempR = new ir_tel_var(this, "LFtempR");
  this->all_vars.push_back(this->LFtempR);
  this->LFtempCL = new ir_tel_var(this, "LFtempCL");
  this->all_vars.push_back(this->LFtempCL);
  this->LFtempCM = new ir_tel_var(this, "LFtempCM");
  this->all_vars.push_back(this->LFtempCM);
  this->LFtempCR = new ir_tel_var(this, "LFtempCR");
  this->all_vars.push_back(this->LFtempCR);
  this->LFwearL = new ir_tel_var(this, "LFwearL");
  this->all_vars.push_back(this->LFwearL);
  this->LFwearM = new ir_tel_var(this, "LFwearM");
  this->all_vars.push_back(this->LFwearM);
  this->LFwearR = new ir_tel_var(this, "LFwearR");
  this->all_vars.push_back(this->LFwearR);
  this->RRshockDefl = new ir_tel_var(this, "RRshockDefl");
  this->all_vars.push_back(this->RRshockDefl);
  this->RRshockVel = new ir_tel_var(this, "RRshockVel");
  this->all_vars.push_back(this->RRshockVel);
  this->LRshockDefl = new ir_tel_var(this, "LRshockDefl");
  this->all_vars.push_back(this->LRshockDefl);
  this->LRshockVel = new ir_tel_var(this, "LRshockVel");
  this->all_vars.push_back(this->LRshockVel);
  this->RFshockDefl = new ir_tel_var(this, "RFshockDefl");
  this->all_vars.push_back(this->RFshockDefl);
  this->RFshockVel = new ir_tel_var(this, "RFshockVel");
  this->all_vars.push_back(this->RFshockVel);
  this->LFshockDefl = new ir_tel_var(this, "LFshockDefl");
  this->all_vars.push_back(this->LFshockDefl);
  this->LFshockVel = new ir_tel_var(this, "LFshockVel");
  this->all_vars.push_back(this->LFshockVel);
  this->LFrideHeight = new ir_tel_var(this, "LFrideHeight");
  this->all_vars.push_back(this->LFrideHeight);
  this->RFrideHeight = new ir_tel_var(this, "RFrideHeight");
  this->all_vars.push_back(this->RFrideHeight);
  this->LRrideHeight = new ir_tel_var(this, "LRrideHeight");
  this->all_vars.push_back(this->LRrideHeight);
  this->RRrideHeight = new ir_tel_var(this, "RRrideHeight");
  this->all_vars.push_back(this->RRrideHeight);
  this->CFSRrideHeight = new ir_tel_var(this, "CFSRrideHeight");
  this->all_vars.push_back(this->CFSRrideHeight);


}

Telemetry_Data::~Telemetry_Data(){
  delete this->SessionTime;
  delete this->SessionTick;
  delete this->SessionNum;
  delete this->SessionState;
  delete this->SessionUniqueID;
  delete this->SessionFlags;
  delete this->SessionTimeRemain;
  delete this->SessionLapsRemain;
  delete this->SessionLapsRemainEx;
  delete this->SessionTimeOfDay;
  delete this->DriverMarker;
  delete this->PushToPass;
  delete this->ManualBoost;
  delete this->ManualNoBoost;
  delete this->IsOnTrack;
  delete this->FrameRate;
  delete this->CpuUsageBG;
  delete this->PlayerCarPosition;
  delete this->PlayerCarClassPosition;
  delete this->PlayerTrackSurface;
  delete this->PlayerTrackSurfaceMaterial;
  delete this->PlayerCarIdx;
  delete this->PlayerCarTeamIncidentCount;
  delete this->PlayerCarMyIncidentCount;
  delete this->PlayerCarDriverIncidentCount;
  delete this->PlayerCarWeightPenalty;
  delete this->PlayerCarPowerAdjust;
  delete this->PlayerCarDryTireSetLimit;
  delete this->PlayerCarTowTime;
  delete this->PlayerCarInPitStall;
  delete this->PlayerCarPitSvStatus;
  delete this->PaceMode;
  delete this->OnPitRoad;
  delete this->SteeringWheelAngle;
  delete this->Throttle;
  delete this->Brake;
  delete this->Clutch;
  delete this->Gear;
  delete this->RPM;
  delete this->Lap;
  delete this->LapCompleted;
  delete this->LapDist;
  delete this->LapDistPct;
  delete this->LapBestLap;
  delete this->LapBestLapTime;
  delete this->LapLastLapTime;
  delete this->LapCurrentLapTime;
  delete this->LapLasNLapSeq;
  delete this->LapLastNLapTime;
  delete this->LapBestNLapLap;
  delete this->LapBestNLapTime;
  delete this->LapDeltaToBestLap;
  delete this->LapDeltaToBestLap_DD;
  delete this->LapDeltaToBestLap_OK;
  delete this->LapDeltaToOptimalLap;
  delete this->LapDeltaToOptimalLap_DD;
  delete this->LapDeltaToOptimalLap_OK;
  delete this->LapDeltaToSessionBestLap;
  delete this->LapDeltaToSessionBestLap_DD;
  delete this->LapDeltaToSessionBestLap_OK;
  delete this->LapDeltaToSessionOptimalLap;
  delete this->LapDeltaToSessionOptimalLap_DD;
  delete this->LapDeltaToSessionOptimalLap_OK;
  delete this->LapDeltaToSessionLastlLap;
  delete this->LapDeltaToSessionLastlLap_DD;
  delete this->LapDeltaToSessionLastlLap_OK;
  delete this->Speed;
  delete this->Yaw;
  delete this->YawNorth;
  delete this->Pitch;
  delete this->Roll;
  delete this->EnterExitReset;
  delete this->Lat;
  delete this->Lon;
  delete this->Alt;
  delete this->TrackTemp;
  delete this->TrackTempCrew;
  delete this->AirTemp;
  delete this->WeatherType;
  delete this->Skies;
  delete this->AirDensity;
  delete this->AirPressure;
  delete this->WindVel;
  delete this->WindDir;
  delete this->RelativeHumidity;
  delete this->FogLevel;
  delete this->PitsOpen;
  delete this->PitRepairLeft;
  delete this->PitOptRepairLeft;
  delete this->PitstopActive;
  delete this->FastRepairUsed;
  delete this->FastRepairAvailable;
  delete this->LFTiresUsed;
  delete this->RFTiresUsed;
  delete this->LRTiresUsed;
  delete this->RRTiresUsed;
  delete this->LeftTireSetsUsed;
  delete this->RightTireSetsUsed;
  delete this->FrontTireSetsUsed;
  delete this->RearTireSetsUsed;
  delete this->TireSetsUsed;
  delete this->LFTiresAvailable;
  delete this->RFTiresAvailable;
  delete this->LRTiresAvailable;
  delete this->RRTiresAvailable;
  delete this->LeftTireSetsAvailable;
  delete this->RightTireSetsAvailable;
  delete this->FrontTireSetsAvailable;
  delete this->RearTireSetsAvailable;
  delete this->TireSetsAvailable;
  delete this->IsOnTrackCar;
  delete this->SteeringWheelPctTorque;
  delete this->SteeringWheelPctTorqueSign;
  delete this->SteeringWheelPctTorqueSignStops;
  delete this->SteeringWheelPctDamper;
  delete this->SteeringWheelAngleMax;
  delete this->ShiftIndicatorPct;
  delete this->ShiftPowerPct;
  delete this->ShiftGrindRPM;
  delete this->ThrottleRaw;
  delete this->BrakeRaw;
  delete this->HandbrakeRaw;
  delete this->EngineWarnings;
  delete this->FuelLevel;
  delete this->FuelLevelPct;
  delete this->PitSvFlags;
  delete this->PitSvLFP;
  delete this->PitSvRFP;
  delete this->PitSvLRP;
  delete this->PitSvRRP;
  delete this->PitSvFuel;
  delete this->TireLF_RumblePitch;
  delete this->TireRF_RumblePitch;
  delete this->TireLR_RumblePitch;
  delete this->TireRR_RumblePitch;
  delete this->SteeringWheelTorque;
  delete this->VelocityZ;
  delete this->VelocityY;
  delete this->VelocityX;
  delete this->YawRate;
  delete this->PitchRate;
  delete this->RollRate;
  delete this->VertAccel;
  delete this->LatAccel;
  delete this->LongAccel;
  delete this->dcStarter;
  delete this->dcPitSpeedLimiterToggle;
  delete this->dcTractionControlToggle;
  delete this->dcHeadlightFlash;
  delete this->dcTearOffVisor;
  delete this->dpRFTireChange;
  delete this->dpLFTireChange;
  delete this->dpRRTireChange;
  delete this->dpLRTireChange;
  delete this->dpFuelFill;
  delete this->dpFuelAddKg;
  delete this->dpFastRepair;
  delete this->dcBrakeBias;
  delete this->dpLFTireColdPress;
  delete this->dpRFTireColdPress;
  delete this->dpLRTireColdPress;
  delete this->dpRRTireColdPress;
  delete this->dcEnginePower;
  delete this->dpPowerSteering;
  delete this->dcTractionControl;
  delete this->dcTractionControl2;
  delete this->WaterTemp;
  delete this->WaterLevel;
  delete this->FuelPress;
  delete this->FuelUsePerHour;
  delete this->OilTemp;
  delete this->OilPress;
  delete this->OilLevel;
  delete this->Voltage;
  delete this->ManifoldPress;
  delete this->RRspeed;
  delete this->RRpressure;
  delete this->RRcoldPressure;
  delete this->RRtempL;
  delete this->RRtempM;
  delete this->RRtempR;
  delete this->RRtempCL;
  delete this->RRtempCM;
  delete this->RRtempCR;
  delete this->RRwearL;
  delete this->RRwearM;
  delete this->RRwearR;
  delete this->LRspeed;
  delete this->LRpressure;
  delete this->LRcoldPressure;
  delete this->LRtempL;
  delete this->LRtempM;
  delete this->LRtempR;
  delete this->LRtempCL;
  delete this->LRtempCM;
  delete this->LRtempCR;
  delete this->LRwearL;
  delete this->LRwearM;
  delete this->LRwearR;
  delete this->RFspeed;
  delete this->RFpressure;
  delete this->RFcoldPressure;
  delete this->RFtempL;
  delete this->RFtempM;
  delete this->RFtempR;
  delete this->RFtempCL;
  delete this->RFtempCM;
  delete this->RFtempCR;
  delete this->RFwearL;
  delete this->RFwearM;
  delete this->RFwearR;
  delete this->LFspeed;
  delete this->LFpressure;
  delete this->LFcoldPressure;
  delete this->LFtempL;
  delete this->LFtempM;
  delete this->LFtempR;
  delete this->LFtempCL;
  delete this->LFtempCM;
  delete this->LFtempCR;
  delete this->LFwearL;
  delete this->LFwearM;
  delete this->LFwearR;
  delete this->RRshockDefl;
  delete this->RRshockVel;
  delete this->LRshockDefl;
  delete this->LRshockVel;
  delete this->RFshockDefl;
  delete this->RFshockVel;
  delete this->LFshockDefl;
  delete this->LFshockVel;
  delete this->LFrideHeight;
  delete this->RFrideHeight;
  delete this->LRrideHeight;
  delete this->RRrideHeight;
  delete this->CFSRrideHeight;
}
