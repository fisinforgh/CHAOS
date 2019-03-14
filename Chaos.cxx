///////////////////////////////////////////////////////////////////////////
//                                                                       //
// NOTICE OF COPYRIGHT                                                   //
//                                                                       //
//                       Copyright (C) 2019                              //
//                Arnold Alonso¹  - Julian Salamanca²                    //
//                                                                       //
//                aralonsoa@correo.udistrital.edu.co¹                    //
//                   jasalamanca@udistrital.edu.co²                      //
//                                                                       //
//       ¹²Grupo de Física e Informática (FISINFOR) Universidad          //
//                  Distrital Francisco José de Caldas                   //
//                                                                       //
//                                                                       //
//                 https://github.com/fisinforgh/CHAOS                   //
//                                                                       //
// This program is free software; you can redistribute it and/or modify  //
// it under the terms of the GNU General Public License as published by  //
// the Free Software Foundation; either version 2 of the License, or     //
// (at your option) any later version.                                   //
//                                                                       //
// This program is distributed in the hope that it will be useful,       //
// but WITHOUT ANY WARRANTY; without even the implied warranty of        //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         //
// GNU General Public License for more details:                          //
//                                                                       //
//               http://www.gnu.org/copyleft/gpl.html                    //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

#ifndef __CINT__
#ifndef ROOT_TApplication
#include "TApplication.h"
#endif
#include "include/WMainSELECT.h"
#endif

#ifdef __CINT__
#include "include/types.h"
#endif

int Chaos(){
  WMainSELECT *App = new WMainSELECT(gClient -> GetRoot(), 10, 10, kMainFrame | kVerticalFrame);
  return 0;
}

#ifndef __CINT__
int main(int argc, char** argv){
  TApplication ChaosApp("ChaosApp", &argc, argv);
  int retVal = Chaos();
  ChaosApp.Run();
  return retVal;
}
#endif
