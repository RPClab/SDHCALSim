#pragma once

#include "G4UserEventAction.hh"

#include <ctime>
#include <chrono>

class SDHCALRunAction;
class SDHCALSteppingAction;
class SDHCALStackingAction;
class SDHCALTrackingAction;
class SDHCALPrimaryGeneratorAction;

#include "G4AutoLock.hh"
  
namespace
{
  G4Mutex aMutex=G4MUTEX_INITIALIZER;
}
  


class SDHCALEventAction : public G4UserEventAction
{
public :
  SDHCALEventAction(SDHCALRunAction*,SDHCALSteppingAction*,SDHCALStackingAction*,SDHCALTrackingAction*,SDHCALPrimaryGeneratorAction*);
  virtual ~SDHCALEventAction() = default ;

  virtual void BeginOfEventAction(const G4Event* event) ;
  virtual void EndOfEventAction(const G4Event* event) ;

private :
  std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
  double averageTime{0.};
  unsigned int nEventsProcessed{0};
  SDHCALRunAction* m_RunAction{nullptr};
  SDHCALSteppingAction* m_SteppingAction{nullptr};
  SDHCALStackingAction* m_StackingAction{nullptr};
  SDHCALTrackingAction* m_TrackingAction{nullptr};
  SDHCALPrimaryGeneratorAction* m_PrimaryGeneratorAction{nullptr};
};
