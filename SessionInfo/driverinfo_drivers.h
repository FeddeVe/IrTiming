#ifndef DRIVERINFO_DRIVERS_H
#define DRIVERINFO_DRIVERS_H

#include <QObject>
#include <QDebug>

class DriverInfo_Drivers : public QObject
{
  Q_OBJECT
public:
  explicit DriverInfo_Drivers(QObject *parent = nullptr);

  void set_value(QString key, QString value);

  QString get_CarIdx();
  QString get_UserName();
  QString get_AbbrevName();
  QString get_Initials();
  QString get_UserID();
  QString get_TeamID();
  QString get_TeamName();
  QString get_CarNumber();
  QString get_CarNumberRaw();
  QString get_CarPath();
  QString get_CarClassID();
  QString get_CarID();
  QString get_CarIsPaceCar();
  QString get_CarIsAI();
  QString get_CarScreenName();
  QString get_CarScreenNameShort();
  QString get_CarClassShortName();
  QString get_CarClassRelSpeed();
  QString get_CarClassLicenseLevel();
  QString get_CarClassMaxFuelPct();
  QString get_CarClassWeightPenalty();
  QString get_CarClassPowerAdjust();
  QString get_CarClassDryTireSetLimit();
  QString get_CarClassColor();
  QString get_IRating();
  QString get_LicLevel();
  QString get_LicSubLevel();
  QString get_LicString();
  QString get_LicColor();
  QString get_IsSpectator();
  QString get_CarDesignStr();
  QString get_HelmetDesignStr();
  QString get_SuitDesignStr();
  QString get_CarNumberDesignStr();
  QString get_CarSponsor_1();
  QString get_CarSponsor_2();
  QString get_ClubName();
  QString get_DivisionName();
  QString get_CurDriverIncidentCount();
  QString get_TeamIncidentCount();


signals:

public slots:

private:
  QString CarIdx;
  QString UserName;
  QString AbbrevName;
  QString Initials;
  QString UserID;
  QString TeamID;
  QString TeamName;
  QString CarNumber;
  QString CarNumberRaw;
  QString CarPath;
  QString CarClassID;
  QString CarID;
  QString CarIsPaceCar;
  QString CarIsAI;
  QString CarScreenName;
  QString CarScreenNameShort;
  QString CarClassShortName;
  QString CarClassRelSpeed;
  QString CarClassLicenseLevel;
  QString CarClassMaxFuelPct;
  QString CarClassWeightPenalty;
  QString CarClassPowerAdjust;
  QString CarClassDryTireSetLimit;
  QString CarClassColor;
  QString IRating;
  QString LicLevel;
  QString LicSubLevel;
  QString LicString;
  QString LicColor;
  QString IsSpectator;
  QString CarDesignStr;
  QString HelmetDesignStr;
  QString SuitDesignStr;
  QString CarNumberDesignStr;
  QString CarSponsor_1;
  QString CarSponsor_2;
  QString ClubName;
  QString DivisionName;
  QString CurDriverIncidentCount;
  QString TeamIncidentCount;

};

#endif // DRIVERINFO_DRIVERS_H
