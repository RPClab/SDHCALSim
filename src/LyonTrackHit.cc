#include "LyonTrackHit.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include "G4VProcess.hh"

LyonTrackHit::LyonTrackHit(const G4Step* aStep,int replicaCountLevel)
{
  _energyDeposited=aStep->GetTotalEnergyDeposit();
  _entrancePoint=aStep->GetPreStepPoint()->GetPosition();
  _exitPoint=aStep->GetPostStepPoint()->GetPosition();
  _deltaPosition=aStep->GetDeltaPosition();
  G4TouchableHistory * theTouchable = 
    (G4TouchableHistory *) aStep->GetPreStepPoint()->GetTouchable();
  _replicaCopyNumber=theTouchable->GetReplicaNumber(replicaCountLevel);
  _enteringStep=(aStep->GetPreStepPoint()->GetStepStatus()==fGeomBoundary);
  _leavingStep=(aStep->GetPostStepPoint()->GetStepStatus()==fGeomBoundary);
  _pdgID=aStep->GetTrack()->GetDynamicParticle()->GetPDGcode();
  _time=aStep->GetPostStepPoint()->GetGlobalTime();
  //Add by Anais
  _momentum=aStep->GetTrack()->GetMomentum();
  //add by rhan
  _trackid=aStep->GetTrack()->GetTrackID();
  _parentid=aStep->GetTrack()->GetParentID();
  //  G4cout<<"A "<<aStep->GetTrack()->GetDynamicParticle()->GetDefinition()->GetParticleName()<<" enters gap "<<_replicaCopyNumber<<" at time "<<aStep->GetPreStepPoint()->GetGlobalTime()<<" and exits at "<<aStep->GetPostStepPoint()->GetGlobalTime()<<G4endl;
  _charge=(int) aStep->GetTrack()->GetDynamicParticle()->GetCharge();
  
  //G4cout<<aStep->GetTrack()->GetCreatorProcess()<<G4endl;
  //  if(aStep->GetTrack()->GetCreatorProcess() != 0)processName = aStep->GetTrack()->GetCreatorProcess()->GetProcessName();
  //G4cout<<"g4 processName= ***********************"<<processName<<G4endl;
}
