#ifndef SDHCALGun_h
#define SDHCALGun_h

#include <G4ParticleGun.hh>


struct SDHCALGunOptions
{
		G4String particleName = "pi-" ;
		G4String gunOptionEnergyDistribution = "fixed" ;

		G4double particleEnergy = 30 * CLHEP::GeV ;
		G4double sigmaEnergy = 0.1 * CLHEP::GeV ;
		G4double minEnergy = 30 * CLHEP::GeV ;
		G4double maxEnergy = 30 * CLHEP::GeV ;

		G4String gunOptionPosition = "fixed" ;

		G4double meanPositionX = 0.0 * CLHEP::mm ;
		G4double meanPositionY = 0.0 * CLHEP::mm ;
		G4double meanPositionZ = -20.0 * CLHEP::mm ;
		G4double uniformMaxPosition = 0.0 * CLHEP::mm ; //uniform position
		G4double sigmaPosition = 1 * CLHEP::mm ; //gaussian position


		G4String gunOptionMomentum = "fixed" ;
		G4ThreeVector primaryMom ;

		G4double gaussianMomentumSigma = 0.1 ;
		G4double momentumTheta = 0 ;
		G4double momentumPhi = 0 ;

		G4double time = 0 * CLHEP::ns ;
} ;


class SDHCALGun : public G4ParticleGun
{
	public :
		SDHCALGun() ;
		SDHCALGun(const SDHCALGunOptions& opt) ;
		~SDHCALGun() ;


		void generatePrimary(G4Event* event) ;


	protected :
		void shootPosition() ;
		void shootMomentum() ;
		void shootForCosmic() ;

		void shootEnergy() ;

		SDHCALGunOptions options ;
} ;


#endif //SDHCALGun_h


//G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable() ;
//G4String particleName = "pi-" ;
//particleDefinition = particleTable->FindParticle(particleName) ;


//primaryPos = G4ThreeVector(0 , 0 , -20*CLHEP::mm) ;
//primaryMom = G4ThreeVector(0 , 0 , 1) ;
//primaryEnergy = particleEnergy ;
