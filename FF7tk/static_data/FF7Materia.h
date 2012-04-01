/****************************************************************************/
//    copyright 2012  Chris Rizzitello <sithlord48@gmail.com>               //
//                                                                          //
//    This file is part of <UnNamedToolKit>                                 //
//                                                                          //
//  <UnNamedToolKit> is free software: you can redistribute it and/or modify//
//    it under the terms of the GNU General Public License as published by  //
//    the Free Software Foundation, either version 3 of the License, or     //
//    (at your option) any later version.                                   //
//                                                                          //
// <UnNamedToolKit> is distributed in the hope that it will be useful,      //
//    but WITHOUT ANY WARRANTY; without even the implied warranty of        //
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          //
//    GNU General Public License for more details.                          //
/****************************************************************************/
#ifndef FF7MATERIA_H
    #define FF7MATERIA_H
#include <QObject>
#include <QImage>
#include <QIcon>

#include "icons/Materia_Icons/command.xpm"
#include "icons/Materia_Icons/magic.xpm"
#include "icons/Materia_Icons/summon.xpm"
#include "icons/Materia_Icons/support.xpm"
#include "icons/Materia_Icons/independent.xpm"
#include "icons/Materia_Icons/command_star_empty.xpm"
#include "icons/Materia_Icons/magic_star_empty.xpm"
#include "icons/Materia_Icons/summon_star_empty.xpm"
#include "icons/Materia_Icons/support_star_empty.xpm"
#include "icons/Materia_Icons/independent_star_empty.xpm"
#include "icons/Materia_Icons/command_star_full.xpm"
#include "icons/Materia_Icons/magic_star_full.xpm"
#include "icons/Materia_Icons/summon_star_full.xpm"
#include "icons/Materia_Icons/support_star_full.xpm"
#include "icons/Materia_Icons/independent_star_full.xpm"


struct MATERIA
{
    QString name;
    QString skills[5];
    QString stats;
    QImage m_image;
    QImage em_image;
    QImage fm_image;
    quint8 id;
    qint8 hp;
    qint8 mp;
    qint8 str;
    qint8 vit;
    qint8 dex;
    qint8 lck;
    qint8 mag;
    qint8 spi;//for use in hp/mp/char stat calculations (maybe later)
    qint32 ap[5]; //ap needed for levels.
    qint8 type; //1-magic,2-summon,3-independent,4-support,5-command,0-unknown
    qint8 levels;
};

class FF7Materia
{
public:
    QString Name(int id);
    QImage Image(int id);
    QImage Image_EmptyStar(int id);
    QImage Image_FullStar(int id);
    QIcon Icon(int id);
    QString Skills(int id,int lvl);
    QString Stat_String(int id);
    qint8 Stat_Str(int id);
    qint8 Stat_Vit(int id);
    qint8 Stat_Mag(int id);
    qint8 Stat_Spi(int id);
    qint8 Stat_Dex(int id);
    qint8 Stat_Lck(int id);
    qint8 Stat_Hp(int id);
    qint8 Stat_Mp(int id);
    qint8 Levels(int id);
    quint8 Type(int id);
    qint32 Ap(int id,int lvl);
    //Static Icon for all materia..
    QIcon Icon_AllMateria();
    QImage Image_AllMateria();
    // Return Eskill name;
    QString Eskill(int i);
};

static MATERIA Materias[]=
{
    {QT_TRANSLATE_NOOP("Materia_Names","MP Plus"),         {QT_TRANSLATE_NOOP("Materia_Skills","MP Plus +10%"),QT_TRANSLATE_NOOP("Materia_Skills","MP Plus +20%"),QT_TRANSLATE_NOOP("Materia_Skills","MP Plus +30%"),QT_TRANSLATE_NOOP("Materia_Skills","MP Plus +40%"),QT_TRANSLATE_NOOP("Materia_Skills","MP Plus +50%")},QT_TRANSLATE_NOOP("Materia_Stats","MaxMp:+% depending on level"), QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x00,0,0,0,0,0,0,0,0,{0,10000,20000,30000,50000},3,5},
    {QT_TRANSLATE_NOOP("Materia_Names","HP Plus"),         {QT_TRANSLATE_NOOP("Materia_Skills","HP Plus +10%"),QT_TRANSLATE_NOOP("Materia_Skills","HP Plus +20%"),QT_TRANSLATE_NOOP("Materia_Skills","HP Plus +30%"),QT_TRANSLATE_NOOP("Materia_Skills","HP Plus +40%"),QT_TRANSLATE_NOOP("Materia_Skills","HP Plus +50%")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:+% depending on level"), QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x01,0,0,0,0,0,0,0,0,{0,10000,20000,30000,50000},3,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Speed Plus"),      {QT_TRANSLATE_NOOP("Materia_Skills","Speed Plus +10%"),QT_TRANSLATE_NOOP("Materia_Skills","Speed Plus +20%"),QT_TRANSLATE_NOOP("Materia_Skills","Speed Plus +30%"),QT_TRANSLATE_NOOP("Materia_Skills","Speed Plus +40%"),QT_TRANSLATE_NOOP("Materia_Skills","Speed Plus +50%")},QT_TRANSLATE_NOOP("Materia_Stats","Dex:+% depending on level"), QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x02,0,0,0,0,0,0,0,0,{0,15000,30000,60000,100000},3,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Magic Plus"),      {QT_TRANSLATE_NOOP("Materia_Skills","Magic Plus +10%"),QT_TRANSLATE_NOOP("Materia_Skills","Magic Plus +20%"),QT_TRANSLATE_NOOP("Materia_Skills","Magic Plus +30%"),QT_TRANSLATE_NOOP("Materia_Skills","Magic Plus +40%"),QT_TRANSLATE_NOOP("Materia_Skills","Magic Plus +50%")},QT_TRANSLATE_NOOP("Materia_Stats","Mag:+% depending on level"), QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x03,0,0,0,0,0,0,0,0,{0,10000,20000,30000,50000},3,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Luck Plus"),       {QT_TRANSLATE_NOOP("Materia_Skills","Luck Plus +10%"),QT_TRANSLATE_NOOP("Materia_Skills","Luck Plus +20%"),QT_TRANSLATE_NOOP("Materia_Skills","Luck Plus +30%"),QT_TRANSLATE_NOOP("Materia_Skills","Luck Plus +40%"),QT_TRANSLATE_NOOP("Materia_Skills","Luck Plus +50%")},QT_TRANSLATE_NOOP("Materia_Stats","Lck:+% depending on level"), QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x04,0,0,0,0,0,0,0,0,{0,15000,30000,60000,100000},3,5},
    {QT_TRANSLATE_NOOP("Materia_Names","EXP Plus"),        {QT_TRANSLATE_NOOP("Materia_Skills","Exp Plus +50%"),QT_TRANSLATE_NOOP("Materia_Skills","Exp Plus +100%"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","Lck:+1"), QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x05,0,0,0,0,0,+1,0,0,{0,60000,150000,0,0},3,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Gil Plus"),        {QT_TRANSLATE_NOOP("Materia_Skills","Gil Plus +50%"),QT_TRANSLATE_NOOP("Materia_Skills","Gil Plus +100%"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","Lck:+1"), QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x06,0,0,0,0,0,+1,0,0,{0,80000,150000,0,0},3,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Enemy Away"),      {QT_TRANSLATE_NOOP("Materia_Skills","Encounter Rate -50%"),QT_TRANSLATE_NOOP("Materia_Skills","Encounter Rate -75%"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","Lck:+1"), QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x07,0,0,0,0,0,+1,0,0,{0,10000,50000,0,0},3,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Enemy Lure"),      {QT_TRANSLATE_NOOP("Materia_Skills","Encounter Rate +50%"),QT_TRANSLATE_NOOP("Materia_Skills","Encounter Rate +100%"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","Lck:-1"), QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x08,0,0,0,0,0,-1,0,0,{0,10000,50000,0,0},3,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Chocobo Lure"),    {QT_TRANSLATE_NOOP("Materia_Skills","Chocobo Lure"),QT_TRANSLATE_NOOP("Materia_Skills","Chocobo Lure +50%"),QT_TRANSLATE_NOOP("Materia_Skills","Chocobo Lure +100%"),QT_TRANSLATE_NOOP("Materia_Skills","Chocobo Lure +200%"),QT_TRANSLATE_NOOP("Materia_Skills","")},QT_TRANSLATE_NOOP("Materia_Stats","Lck:+1"), QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x09,0,0,0,0,0,+1,0,0,{0,3000,10000,30000,0},3,4},
    {QT_TRANSLATE_NOOP("Materia_Names","Pre-emptive"),     {QT_TRANSLATE_NOOP("Materia_Skills","Pre-emptive +6%"),QT_TRANSLATE_NOOP("Materia_Skills","Pre-emptive +12%"),QT_TRANSLATE_NOOP("Materia_Skills","Pre-emptive +24%"),QT_TRANSLATE_NOOP("Materia_Skills","Pre-emptive +36%"),QT_TRANSLATE_NOOP("Materia_Skills","Pre-emptive +48%")},QT_TRANSLATE_NOOP("Materia_Stats","Dex:+2"), QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x0A,0,0,0,0,+2,0,0,0,{0,8000,20000,40000,80000},3,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Long Range"),      {QT_TRANSLATE_NOOP("Materia_Skills","Long Range"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x0B,0,0,0,0,0,0,0,0,{0,80000,0,0,0},3,2},
    {QT_TRANSLATE_NOOP("Materia_Names","Mega All"),        {QT_TRANSLATE_NOOP("Materia_Skills","Mega-all x1"),QT_TRANSLATE_NOOP("Materia_Skills","Mega-all x2"),QT_TRANSLATE_NOOP("Materia_Skills","Mega-all x3"),QT_TRANSLATE_NOOP("Materia_Skills","Mega-all x4"),QT_TRANSLATE_NOOP("Materia_Skills","Mega-all x5")},"", QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x0C,0,0,0,0,0,0,0,0,{0,20000,40000,80000,160000},3,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Counter Attack"),  {QT_TRANSLATE_NOOP("Materia_Skills","Counter Attack 20%"),QT_TRANSLATE_NOOP("Materia_Skills","Counter Attack 40%"),QT_TRANSLATE_NOOP("Materia_Skills","Counter Attack 60%"),QT_TRANSLATE_NOOP("Materia_Skills","Counter Attack 80%"),QT_TRANSLATE_NOOP("Materia_Skills","Counter Attack 100%")},"", QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x0D,0,0,0,0,0,0,0,0,{0,10000,20000,50000,100000},3,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Slash-All"),       {QT_TRANSLATE_NOOP("Materia_Skills","Slash-All"),QT_TRANSLATE_NOOP("Materia_Skills","Flash"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},"", QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x0E,0,0,0,0,0,0,0,0,{0,130000,150000,0,0},5,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Double Cut"),      {QT_TRANSLATE_NOOP("Materia_Skills","2x-Cut"),QT_TRANSLATE_NOOP("Materia_Skills","4x-Cut"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","Dex:+2"), QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x0F,0,0,0,0,+2,0,0,0,{0,100000,150000,0,0},5,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Cover"),           {QT_TRANSLATE_NOOP("Materia_Skills","Cover +20%"),QT_TRANSLATE_NOOP("Materia_Skills","Cover +40%"),QT_TRANSLATE_NOOP("Materia_Skills","Cover +60%"),QT_TRANSLATE_NOOP("Materia_Skills","Cover +80%"),QT_TRANSLATE_NOOP("Materia_Skills","Cover +100%")},QT_TRANSLATE_NOOP("Materia_Stats","Vit:+1"), QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x10,0,0,0,+1,0,0,0,0,{0,2000,10000,25000,40000},3,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Underwater"),      {QT_TRANSLATE_NOOP("Materia_Skills","Underwater"),"","","",""},"", QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x11,0,0,0,0,0,0,0,0,{0,0,0,0,0},3,1},
    {QT_TRANSLATE_NOOP("Materia_Names","HP <-> MP"),       {QT_TRANSLATE_NOOP("Materia_Skills","HP <-> MP"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(independent_xpm),QImage(independent_star_empty_xpm),QImage(independent_star_full_xpm), 0x12,0,0,0,0,0,0,0,0,{0,80000,0,0,0},3,2},
    {QT_TRANSLATE_NOOP("Materia_Names","W-Magic"),         {QT_TRANSLATE_NOOP("Materia_Skills","W-Magic"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x13,0,0,0,0,0,0,0,0,{0,250000,0,0,0},5,2},
    {QT_TRANSLATE_NOOP("Materia_Names","W-Summon"),        {QT_TRANSLATE_NOOP("Materia_Skills","W-Summon"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x14,0,0,0,0,0,0,0,0,{0,250000,0,0,0},5,2},
    {QT_TRANSLATE_NOOP("Materia_Names","W-Item"),          {QT_TRANSLATE_NOOP("Materia_Skills","W-Item"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x15,0,0,0,0,0,0,0,0,{0,250000,0,0,0},5,2},
    {QT_TRANSLATE_NOOP("Materia_Names","DON'T USE"),       {"?","?","?","?","?"},"ID:0x16",QImage(),QImage(),QImage(),0X16,0,0,0,0,0,0,0,0,{0,0,0,0,0},0,0},
    {QT_TRANSLATE_NOOP("Materia_Names","All"),             {QT_TRANSLATE_NOOP("Materia_Skills","All x1"),QT_TRANSLATE_NOOP("Materia_Skills","All x2"),QT_TRANSLATE_NOOP("Materia_Skills","All x3"),QT_TRANSLATE_NOOP("Materia_Skills","All x4"),QT_TRANSLATE_NOOP("Materia_Skills","All x5")},"", QImage(support_xpm),QImage(support_star_empty_xpm),QImage(support_star_full_xpm),     0x17,0,0,0,0,0,0,0,0,{0,1500,6000,18000,35000},4,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Counter"),         {QT_TRANSLATE_NOOP("Materia_Skills","Counter Rate 20%"),QT_TRANSLATE_NOOP("Materia_Skills","Counter Rate 40%"),QT_TRANSLATE_NOOP("Materia_Skills","Counter Rate 60%"),QT_TRANSLATE_NOOP("Materia_Skills","Counter Rate 80%"),QT_TRANSLATE_NOOP("Materia_Skills","Counter Rate 100%")},"", QImage(support_xpm),QImage(support_star_empty_xpm),QImage(support_star_full_xpm),     0x18,0,0,0,0,0,0,0,0,{0,20000,40000,60000,100000},4,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Magic Counter"),   {QT_TRANSLATE_NOOP("Materia_Skills","Magic Counter Rate 30%"),QT_TRANSLATE_NOOP("Materia_Skills","Magic Counter Rate 40%"),QT_TRANSLATE_NOOP("Materia_Skills","Magic Counter Rate 60%"),QT_TRANSLATE_NOOP("Materia_Skills","Magic Counter Rate 80%"),QT_TRANSLATE_NOOP("Materia_Skills","Magic Counter Rate 100%")},"", QImage(support_xpm),QImage(support_star_empty_xpm),QImage(support_star_full_xpm),     0x19,0,0,0,0,0,0,0,0,{0,20000,40000,80000,300000},4,5},
    {QT_TRANSLATE_NOOP("Materia_Names","MP Turbo"),        {QT_TRANSLATE_NOOP("Materia_Skills","MP Turbo 10%"),QT_TRANSLATE_NOOP("Materia_Skills","Mp Turbo 20%"),QT_TRANSLATE_NOOP("Materia_Skills","Mp Turbo 30%"),QT_TRANSLATE_NOOP("Materia_Skills","Mp Turbo 40%"),QT_TRANSLATE_NOOP("Materia_Skills","Mp Turbo 50%")},"", QImage(support_xpm),QImage(support_star_empty_xpm),QImage(support_star_full_xpm),     0x1A,0,0,0,0,0,0,0,0,{0,10000,30000,60000,120000},4,5},
    {QT_TRANSLATE_NOOP("Materia_Names","MP Absorb"),       {QT_TRANSLATE_NOOP("Materia_Skills","MP Absorb"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(support_xpm),QImage(support_star_empty_xpm),QImage(support_star_full_xpm),     0x1B,0,0,0,0,0,0,0,0,{0,100000,0,0,0},4,2},
    {QT_TRANSLATE_NOOP("Materia_Names","HP Absorb"),       {QT_TRANSLATE_NOOP("Materia_Skills","HP Absorb"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(support_xpm),QImage(support_star_empty_xpm),QImage(support_star_full_xpm),     0x1C,0,0,0,0,0,0,0,0,{0,100000,0,0,0},4,2},
    {QT_TRANSLATE_NOOP("Materia_Names","Elemental"),       {QT_TRANSLATE_NOOP("Materia_Skills","Elemental 50%"),QT_TRANSLATE_NOOP("Materia_Skills","Elemental 100%"),QT_TRANSLATE_NOOP("Materia_Skills","Elemental 200%"),QT_TRANSLATE_NOOP("Materia_Skills",""),""},"", QImage(support_xpm),QImage(support_star_empty_xpm),QImage(support_star_full_xpm),     0x1D,0,0,0,0,0,0,0,0,{0,10000,40000,80000,0},4,4},
    {QT_TRANSLATE_NOOP("Materia_Names","Added Effect"),    {QT_TRANSLATE_NOOP("Materia_Skills","Added Effect"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(support_xpm),QImage(support_star_empty_xpm),QImage(support_star_full_xpm),     0x1E,0,0,0,0,0,0,0,0,{0,100000,0,0,0},4,2},
    {QT_TRANSLATE_NOOP("Materia_Names","Sneak Attack"),    {QT_TRANSLATE_NOOP("Materia_Skills","Sneak Attack 20%"),QT_TRANSLATE_NOOP("Materia_Skills","Sneak Attack 35%"),QT_TRANSLATE_NOOP("Materia_Skills","Sneak Attack 50%"),QT_TRANSLATE_NOOP("Materia_Skills","Sneak Attack 65%"),QT_TRANSLATE_NOOP("Materia_Skills","Sneak Attack 80%")},"", QImage(support_xpm),QImage(support_star_empty_xpm),QImage(support_star_full_xpm),     0x1F,0,0,0,0,0,0,0,0,{0,20000,60000,100000,150000},4,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Final Attack"),    {QT_TRANSLATE_NOOP("Materia_Skills","Final Attack x1"),QT_TRANSLATE_NOOP("Materia_Skills","Final Attack x2"),QT_TRANSLATE_NOOP("Materia_Skills","Final Attack x3"),QT_TRANSLATE_NOOP("Materia_Skills","Final Attack x4"),QT_TRANSLATE_NOOP("Materia_Skills","Final Attack x5")},"", QImage(support_xpm),QImage(support_star_empty_xpm),QImage(support_star_full_xpm),     0x20,0,0,0,0,0,0,0,0,{0,20000,40000,80000,160000},4,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Added Cut"),       {QT_TRANSLATE_NOOP("Materia_Skills","Added Cut"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(support_xpm),QImage(support_star_empty_xpm),QImage(support_star_full_xpm),     0x21,0,0,0,0,0,0,0,0,{0,200000,0,0,0},4,2},
    {QT_TRANSLATE_NOOP("Materia_Names","Steal-As-Well"),   {QT_TRANSLATE_NOOP("Materia_Skills","Steal as well"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(support_xpm),QImage(support_star_empty_xpm),QImage(support_star_full_xpm),     0x22,0,0,0,0,0,0,0,0,{0,200000,0,0,0},4,2},
    {QT_TRANSLATE_NOOP("Materia_Names","Quadra Magic"),    {QT_TRANSLATE_NOOP("Materia_Skills","Quadra Magic x1"),QT_TRANSLATE_NOOP("Materia_Skills","Quadra Magic x2"),QT_TRANSLATE_NOOP("Materia_Skills","Quadra Magic x3"),QT_TRANSLATE_NOOP("Materia_Skills","Quadra Magic x4"),QT_TRANSLATE_NOOP("Materia_Skills","Quadra Magic x5")},"", QImage(support_xpm),QImage(support_star_empty_xpm),QImage(support_star_full_xpm),     0x23,0,0,0,0,0,0,0,0,{0,40000,80000,120000,200000},4,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Steal"),           {QT_TRANSLATE_NOOP("Materia_Skills","Steal"),QT_TRANSLATE_NOOP("Materia_Skills","Mug"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","Dex:+2"), QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x24,0,0,0,0,+2,0,0,0,{0,40000,50000,0,0},5,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Sense"),           {QT_TRANSLATE_NOOP("Materia_Skills","Sense"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x25,0,0,0,0,0,0,0,0,{0,40000,0,0,0},5,2},
    {QT_TRANSLATE_NOOP("Materia_Names","DON'T USE"),       {"?","?","?","?","?"},"ID:0x26",QImage(),QImage(),QImage(),0X26,0,0,0,0,0,0,0,0,{0,0,0,0,0},0,0},
    {QT_TRANSLATE_NOOP("Materia_Names","Throw"),           {QT_TRANSLATE_NOOP("Materia_Skills","Throw"),QT_TRANSLATE_NOOP("Materia_Skills","Coin"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","Vit:+1"), QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x27,0,0,0,+1,0,0,0,0,{0,45000,60000,0,0},5,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Morph"),           {QT_TRANSLATE_NOOP("Materia_Skills","Morph"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x28,0,0,0,0,0,0,0,0,{0,100000,0,0,0},5,2},
    {QT_TRANSLATE_NOOP("Materia_Names","Deathblow"),       {QT_TRANSLATE_NOOP("Materia_Skills","DeathBlow"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},QT_TRANSLATE_NOOP("Materia_Stats","Lck:+1"), QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x29,0,0,0,0,0,+1,0,0,{0,40000,0,0,0},5,2},
    {QT_TRANSLATE_NOOP("Materia_Names","Manipulate"),      {QT_TRANSLATE_NOOP("Materia_Skills","Manipulate"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x2A,0,0,0,0,0,0,0,0,{0,40000,0,0,0},5,2},
    {QT_TRANSLATE_NOOP("Materia_Names","Mime"),            {QT_TRANSLATE_NOOP("Materia_Skills","Mime"),QT_TRANSLATE_NOOP("Materia_Skills",""),"","",""},"", QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x2B,0,0,0,0,0,0,0,0,{0,100000,0,0,0},5,2},
    {QT_TRANSLATE_NOOP("Materia_Names","Enemy Skill"),     {QT_TRANSLATE_NOOP("Materia_Skills","Enemy Skill"),"","","",""},"", QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x2C,0,0,0,0,0,0,0,0,{16777215,0,0,0,0},5,1},
    {QT_TRANSLATE_NOOP("Materia_Names","DON'T USE"),       {"?","?","?","?","?"},"ID:0x2D",QImage(),QImage(),QImage(),0X2D,0,0,0,0,0,0,0,0,{0,0,0,0,0},0,0},
    {QT_TRANSLATE_NOOP("Materia_Names","DON'T USE"),       {"?","?","?","?","?"},"ID:0x2E",QImage(),QImage(),QImage(),0X2E,0,0,0,0,0,0,0,0,{0,0,0,0,0},0,0},
    {QT_TRANSLATE_NOOP("Materia_Names","DON'T USE"),       {"?","?","?","?","?"},"ID:0x2F",QImage(),QImage(),QImage(),0X2F,0,0,0,0,0,0,0,0,{0,0,0,0,0},0,0},
    {QT_TRANSLATE_NOOP("Materia_Names","Master Command"),  {QT_TRANSLATE_NOOP("Materia_Skills","Master Command"),"","","",""},"", QImage(command_xpm),QImage(command_star_empty_xpm),QImage(command_star_full_xpm),     0x30,0,0,0,0,0,0,0,0,{0,0,0,0,0},5,1},
    {QT_TRANSLATE_NOOP("Materia_Names","Fire"),            {QT_TRANSLATE_NOOP("Materia_Skills","Fire (4mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Fire2 (22mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Fire3 (52mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Str:-1 Mag:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x31,-2,+2,-1,0,0,0,+1,0,{0,2000,18000,35000,0},1,4},
    {QT_TRANSLATE_NOOP("Materia_Names","Ice"),             {QT_TRANSLATE_NOOP("Materia_Skills","Ice (4mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Ice2 (22mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Ice3 (52mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Str:-1 Mag:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x32,-2,+2,-1,0,0,0,+1,0,{0,2000,18000,35000,0},1,4},
    {QT_TRANSLATE_NOOP("Materia_Names","Earth"),           {QT_TRANSLATE_NOOP("Materia_Skills","Quake (6mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Quake2 (28mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Quake3 (68mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Str:-1 Mag:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x33,-2,+2,-1,0,0,0,+1,0,{0,6000,22000,40000,0},1,4},
    {QT_TRANSLATE_NOOP("Materia_Names","Lightning"),       {QT_TRANSLATE_NOOP("Materia_Skills","Bolt (4mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Bolt2 (22mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Bolt3 (52mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Str:-1 Mag:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x34,-2,+2,-1,0,0,0,+1,0,{0,2000,18000,35000,0},1,4},
    {QT_TRANSLATE_NOOP("Materia_Names","Restore"),         {QT_TRANSLATE_NOOP("Materia_Skills","Cure (5mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Cure2 (24mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Regen (30mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Cure3 (64mp)"),QT_TRANSLATE_NOOP("Materia_Skills","")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Str:-1 Mag:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x35,-2,+2,-1,0,0,0,+1,0,{0,2500,17000,25000,40000},1,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Heal"),            {QT_TRANSLATE_NOOP("Materia_Skills","Poisona (3mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Esuna (15mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Resist (120mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Str:-1 Mag:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x36,-2,+2,-1,0,0,0,+1,0,{0,12000,52000,60000,0},1,4},
    {QT_TRANSLATE_NOOP("Materia_Names","Revive"),          {QT_TRANSLATE_NOOP("Materia_Skills","Life (34mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Life2 (100mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-5% MaxMp:+5% Str:-2 Vit:-1 Mag:+2 Spi:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x37,-5,+5,-2,-1,0,0,+2,+1,{0,45000,55000,0,0},1,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Seal"),            {QT_TRANSLATE_NOOP("Materia_Skills","Sleepel (8mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Silence (24mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Str:-1 Mag:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x38,-2,+2,-1,0,0,0,+1,0,{0,10000,20000,0,0},1,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Mystify"),         {QT_TRANSLATE_NOOP("Materia_Skills","Confu (18mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Berserk (28mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Str:-1 Mag:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x39,-2,+2,-1,0,0,0,+1,0,{0,12000,25000,0,0},1,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Transform"),       {QT_TRANSLATE_NOOP("Materia_Skills","Mini (10mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Toad (14mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Str:-1 Mag:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x3A,-2,+2,-1,0,0,0,+1,0,{0,8000,24000,0,0},1,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Exit"),            {QT_TRANSLATE_NOOP("Materia_Skills","Exit (16mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Remove (99mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Str:-1 Mag:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x3B,-2,+2,-1,0,0,0,+1,0,{0,10000,30000,0,0},1,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Poison"),          {QT_TRANSLATE_NOOP("Materia_Skills","Bio (8mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Bio2 (36mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Bio3 (80mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Str:-1 Mag:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x3C,-2,+2,-1,0,0,0,+1,0,{0,5000,20000,38000,0},1,4},
    {QT_TRANSLATE_NOOP("Materia_Names","Gravity"),         {QT_TRANSLATE_NOOP("Materia_Skills","Demi (14mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Demi2 (33mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Demi3 (48mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Str:-1 Mag:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x3D,-2,+2,-1,0,0,0,+1,0,{0,10000,20000,40000,0},1,4},
    {QT_TRANSLATE_NOOP("Materia_Names","Barrier"),         {QT_TRANSLATE_NOOP("Materia_Skills","Barrier (16mp)"),QT_TRANSLATE_NOOP("Materia_Skills","M-Barrier (24mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Reflect (30mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Wall (58mp)"),QT_TRANSLATE_NOOP("Materia_Skills","")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-5% MaxMp:+5% Str:-2 Vit:-1 Mag:+2 Spi:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x3E,-5,+5,-2,-1,0,0,+2,+1,{0,5000,15000,30000,45000},1,5},
    {QT_TRANSLATE_NOOP("Materia_Names","DON'T USE"),       {"?","?","?","?","?"},"ID:0x3F",QImage(),QImage(),QImage(),0X3F,0,0,0,0,0,0,0,0,{0,0,0,0,0},0,0},
    {QT_TRANSLATE_NOOP("Materia_Names","Comet"),           {QT_TRANSLATE_NOOP("Materia_Skills","Comet (70mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Comet2 (110mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-5% MaxMp:+5% Str:-2 Vit:-1 Mag:+2 Spi:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x40,-5,+5,-2,-1,0,0,+2,+1,{0,12000,60000,0,0},1,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Time"),            {QT_TRANSLATE_NOOP("Materia_Skills","Haste (18mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Slow (20mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Stop (34mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-5% MaxMp:+5% Str:-2 Vit:-1 Mag:+2 Spi:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x41,-5,+5,-2,-1,0,0,+2,+1,{0,10000,20000,42000,0},1,4},
    {QT_TRANSLATE_NOOP("Materia_Names","DON'T USE"),       {"?","?","?","?","?"},"ID:0x42",QImage(),QImage(),QImage(),0X42,0,0,0,0,0,0,0,0,{0,0,0,0,0},0,0},
    {QT_TRANSLATE_NOOP("Materia_Names","DON'T USE"),       {"?","?","?","?","?"},"ID:0x43",QImage(),QImage(),QImage(),0X43,0,0,0,0,0,0,0,0,{0,0,0,0,0},0,0},
    {QT_TRANSLATE_NOOP("Materia_Names","Destruct"),        {QT_TRANSLATE_NOOP("Materia_Skills","DeBarrier (12mp)"),QT_TRANSLATE_NOOP("Materia_Skills","DeSpell (20mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Death (30mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-5% MaxMp:+5% Str:-2 Vit:-1 Mag:+2 Spi:+1"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x44,-5,+5,-2,-1,0,0,+2,+1,{0,6000,10000,45000,0},1,4},
    {QT_TRANSLATE_NOOP("Materia_Names","Contain"),         {QT_TRANSLATE_NOOP("Materia_Skills","Freeze (82mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Break (86mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Tornado (90mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Flare (100mp)"),QT_TRANSLATE_NOOP("Materia_Skills","")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-10% MaxMp:+10% Str:-4 Vit:-2 Mag:+4 Spi:+2"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x45,-10,+10,-4,-2,0,0,+4,+2,{0,5000,10000,15000,60000},1,5},
    {QT_TRANSLATE_NOOP("Materia_Names","FullCure"),        {"",QT_TRANSLATE_NOOP("Materia_Skills","Full Cure (99mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-10% MaxMp:+10% Str:-4 Vit:-2 Mag:+4 Spi:+2"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x46,-10,+10,-4,-2,0,0,+4,+2,{0,3000,100000,0,0},1,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Shield"),          {"",QT_TRANSLATE_NOOP("Materia_Skills","Shield (180mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-10% MaxMp:+10% Str:-4 Vit:-2 Mag:+4 Spi:+2"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x47,-10,+10,-4,-2,0,0,+4,+2,{0,10000,100000,0,0},1,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Ultima"),          {"",QT_TRANSLATE_NOOP("Materia_Skills","Ultima (130mp)"),QT_TRANSLATE_NOOP("Materia_Skills",""),"",""},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-10% MaxMp:+10% Str:-4 Vit:-2 Mag:+4 Spi:+2"), QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x48,-10,+10,-4,-2,0,0,+4,+2,{0,5000,100000,0,0},1,3},
    {QT_TRANSLATE_NOOP("Materia_Names","Master Magic"),    {QT_TRANSLATE_NOOP("Materia_Skills","Master Magic"),"","","",""},"", QImage(magic_xpm),QImage(magic_star_empty_xpm),QImage(magic_star_full_xpm),       0x49,0,0,0,0,0,0,0,0,{0,0,0,0,0},1,1},
    {QT_TRANSLATE_NOOP("Materia_Names","Choco/Mog"),       {QT_TRANSLATE_NOOP("Materia_Skills","Choco/Mog x1 (14mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Choco/Mog x2 (14mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Choco/Mog x3 (14mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Choco/Mog x4 (14mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Choco/Mog x5 (14mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Mag:+1"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x4A,-2,+2,0,0,0,0,+1,0,{0,2000,14000,25000,35000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Shiva"),           {QT_TRANSLATE_NOOP("Materia_Skills","Shiva x1 (32mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Shiva x2 (32mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Shiva x3 (32mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Shiva x4 (32mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Shiva x5 (32mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Mag:+1"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x4B,-2,+2,0,0,0,0,+1,0,{0,4000,15000,30000,50000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Ifrit"),           {QT_TRANSLATE_NOOP("Materia_Skills","Ifrit x1 (34mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Ifrit x2 (34mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Ifrit x3 (34mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Ifrit x4 (34mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Ifrit x5 (34mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Mag:+1"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x4C,-2,+2,0,0,0,0,+1,0,{0,5000,20000,35000,60000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Ramuh"),           {QT_TRANSLATE_NOOP("Materia_Skills","Ramuh x1 (40mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Ramuh x2 (40mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Ramuh x3 (40mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Ramuh x4 (40mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Ramuh x5 (40mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Mag:+1"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x4D,-2,+2,0,0,0,0,+1,0,{0,10000,25000,50000,70000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Titan"),           {QT_TRANSLATE_NOOP("Materia_Skills","Titan x1 (46mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Titan x2 (46mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Titan x3 (46mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Titan x4 (46mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Titan x5 (46mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-2% MaxMp:+2% Mag:+1"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x4E,-2,+2,0,0,0,0,+1,0,{0,15000,30000,60000,80000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Odin"),            {QT_TRANSLATE_NOOP("Materia_Skills","Odin x1 (80mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Odin x2 (80mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Odin x3 (80mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Odin x4 (80mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Odin x5 (80mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-5% MaxMp:+5% Mag:+1 Spi:+1"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x4F,-5,+5,0,0,0,0,+1,+1,{0,16000,32000,65000,90000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Leviathan"),       {QT_TRANSLATE_NOOP("Materia_Skills","Leviathan x1 (78mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Leviathan x2 (78mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Leviathan x3 (78mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Leviathan x4 (78mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Leviathan x5 (78mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-5% MaxMp:+5% Mag:+1 Spi:+1"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x50,-5,+5,0,0,0,0,+1,+1,{0,18000,38000,70000,100000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Bahamut"),         {QT_TRANSLATE_NOOP("Materia_Skills","Bahamut x1 (100mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Bahamut x2 (100mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Bahamut x3 (100mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Bahamut x4 (100mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Bahamut x5 (100mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-5% MaxMp:+5% Mag:+1 Spi:+1"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x51,-5,+5,0,0,0,0,+1,+1,{0,20000,50000,80000,120000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Kujata"),          {QT_TRANSLATE_NOOP("Materia_Skills","Kujata x1 (110mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Kujata x2 (110mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Kujata x3 (110mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Kujata x4 (110mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Kujata x5 (110mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-5% MaxMp:+5% Mag:+1 Spi:+1"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x52,-5,+5,0,0,0,0,+1,+1,{0,22000,60000,90000,140000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Alexander"),       {QT_TRANSLATE_NOOP("Materia_Skills","Alexander x1 (120mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Alexander x2 (120mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Alexander x3 (120mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Alexander x4 (120mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Alexander x5 (120mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-5% MaxMp:+5% Mag:+1 Spi:+1"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x53,-5,+5,0,0,0,0,+1,+1,{0,25000,65000,100000,150000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Phoenix"),         {QT_TRANSLATE_NOOP("Materia_Skills","Phoenix x1 (180mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Phoenix x2 (180mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Phoenix x3 (180mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Phoenix x4 (180mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Phoenix x5 (180mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-10% MaxMp:+10% Mag:+2 Spi:+2"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x54,-10,+10,0,0,0,0,+2,+2,{0,28000,70000,120000,180000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Neo Bahamut"),     {QT_TRANSLATE_NOOP("Materia_Skills","Neo Bahamut x1 (140mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Neo Bahamut x2 (140mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Neo Bahamut x3 (140mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Neo Bahamut x4 (140mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Neo Bahamut x5 (140mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-10% MaxMp:+10% Mag:+2 Spi:+2"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x55,-10,+10,0,0,0,0,+2,+2,{0,30000,80000,140000,200000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Hades"),           {QT_TRANSLATE_NOOP("Materia_Skills","Hades x1 (150mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Hades x2 (150mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Hades x3 (150mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Hades x4 (150mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Hades x5 (150mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-10% MaxMp:+15% Mag:+4 Spi:+4"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x56,-10,+15,0,0,0,0,+4,+4,{0,35000,120000,150000,250000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Typhon"),          {QT_TRANSLATE_NOOP("Materia_Skills","Typhon x1 (160mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Typhon x2 (160mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Typhon x3 (160mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Typhon x4 (160mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Typhon x5 (160mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-10% MaxMp:+15% Mag:+4 Spi:+4"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x57,-10,+15,0,0,0,0,+4,+4,{0,35000,120000,150000,250000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Bahamut ZERO"),    {QT_TRANSLATE_NOOP("Materia_Skills","Bahamut ZERO x1 (180mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Bahamut ZERO x2 (180mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Bahamut ZERO x3 (180mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Bahamut ZERO x4 (180mp)"),QT_TRANSLATE_NOOP("Materia_Skills","Bahamut ZERO x5 (180mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-10% MaxMp:+15% Mag:+4 Spi:+4"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x58,-10,+15,0,0,0,0,+4,+4,{0,35000,120000,150000,250000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Knights of Round"),{QT_TRANSLATE_NOOP("Materia_Skills","KOTR x1 (250mp)"),QT_TRANSLATE_NOOP("Materia_Skills","KOTR x2 (250mp)"),QT_TRANSLATE_NOOP("Materia_Skills","KOTR x3 (250mp)"),QT_TRANSLATE_NOOP("Materia_Skills","KOTR x4 (250mp)"),QT_TRANSLATE_NOOP("Materia_Skills","KOTR x5 (250mp)")},QT_TRANSLATE_NOOP("Materia_Stats","MaxHp:-10% MaxMp:+20% Mag:+8 Spi:+8"), QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x59,-10,+20,0,0,0,0,+8,+8,{0,50000,200000,300000,500000},2,5},
    {QT_TRANSLATE_NOOP("Materia_Names","Master Summon"),   {QT_TRANSLATE_NOOP("Materia_Skills","Master Summon"),"","","",""},"",QImage(summon_xpm),QImage(summon_star_empty_xpm),QImage(summon_star_full_xpm),      0x5A,0,0,0,0,0,0,0,0,{0,0,0,0,0},2,1}
};
static QString ESkills[]=
{
    QT_TRANSLATE_NOOP("E_skills","Frog Song"),
    QT_TRANSLATE_NOOP("E_skills","L4 Suicide"),
    QT_TRANSLATE_NOOP("E_skills","Magic Hammer"),
    QT_TRANSLATE_NOOP("E_skills","White Wind"),
    QT_TRANSLATE_NOOP("E_skills","Big Guard"),
    QT_TRANSLATE_NOOP("E_skills","Angel Whisper"),
    QT_TRANSLATE_NOOP("E_skills","Dragon Force"),
    QT_TRANSLATE_NOOP("E_skills","Death Force"),
    QT_TRANSLATE_NOOP("E_skills","Flame Thrower"),
    QT_TRANSLATE_NOOP("E_skills","Laser"),
    QT_TRANSLATE_NOOP("E_skills","Matra Magic"),
    QT_TRANSLATE_NOOP("E_skills","Bad Breath"),
    QT_TRANSLATE_NOOP("E_skills","Beta"),
    QT_TRANSLATE_NOOP("E_skills","Aqualung"),
    QT_TRANSLATE_NOOP("E_skills","Trine"),
    QT_TRANSLATE_NOOP("E_skills","Magic Breath"),
    QT_TRANSLATE_NOOP("E_skills","????"),
    QT_TRANSLATE_NOOP("E_skills","Goblin Punch"),
    QT_TRANSLATE_NOOP("E_skills","Chocobuckle"),
    QT_TRANSLATE_NOOP("E_skills","L5 Death"),
    QT_TRANSLATE_NOOP("E_skills","Death Sentence"),
    QT_TRANSLATE_NOOP("E_skills","Roulette"),
    QT_TRANSLATE_NOOP("E_skills","Shadow Flare"),
    QT_TRANSLATE_NOOP("E_skills","Pandora's Box")
};
#endif //FF7MATERIA_H