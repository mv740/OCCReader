// Copyright (C) 2014-2015  KIT-INR/NK 
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
//

#ifndef GEOM_EDGESOURCE_H 
#define GEOM_EDGESOURCE_H 
#ifdef WNT
#define OCCReader_EXPORTS
#endif
#include "OCC2VTK.h" 

#include <config.h>
#include <TopoDS_Edge.hxx> 
#include <NCollection_Sequence.hxx> 
 
typedef NCollection_Sequence<TopoDS_Edge> TEdgeSet;
 
#include <vtkPoints.h> 
#include <vtkPolyDataAlgorithm.h> 

class vtkPolyData;

class OCC2VTK_EXPORT GEOM_EdgeSource: public vtkPolyDataAlgorithm 
{ 
public: 
  vtkTypeMacro(GEOM_EdgeSource,vtkPolyDataAlgorithm); 
  static GEOM_EdgeSource* New(); 
 
  void AddEdge (const TopoDS_Edge& theEdge,
                bool theIsVector = false);
  void Clear(){ myEdgeSet.Clear();}
  
  void SetVectorMode(bool);

  bool GetVectorMode();
 
  static  
  void OCC2VTK(const TopoDS_Edge& theEdge,  
               vtkPolyData* thePolyData, 
               vtkPoints* thePts,
               bool theIsVector = false); 

  bool IsEmpty(){return myEdgeSet.IsEmpty();}

 
protected: 
  TEdgeSet myEdgeSet;
  // The <myIsVector> flag is common for all edges, because the shape,
  // representing a vector, can have only one edge.
  bool myIsVector, myIsVectorMode;
 
  virtual int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);
 
  GEOM_EdgeSource(); 
  ~GEOM_EdgeSource(); 
 
private: 
  // Not implememnted 
  GEOM_EdgeSource(const GEOM_EdgeSource&); 
  void operator=(const GEOM_EdgeSource&); 
}; 
 
 
#endif //GEOM_EDGESOURCE_H 
