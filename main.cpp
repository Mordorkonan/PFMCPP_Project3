 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

/*
paste your code below
*/
struct Phone
{
    int memoryAmount = 128;
    char numberOfCPUCores = 4;
    float screenSize = 5.8f;
    float cameraResolution = 20.5f;
    float thickness = 0.75f;

    void recieveCalls(int number);
    void capturePhoto(bool frontCamera = false);
    std::string showMessage(int number, bool appendSenderName = false); // returns a message from sender's number
};

struct AirConditioner
{
    float price = 1.95f;
    int screenWidth = 10;
    short remoteDistance = 20;
    float temperatureRange = 55.6f;
    short power = 24;

    bool turnOffAutomatically(char timer); // returns True on success
    void startCooling(float targetTemperature, char timer = 0);
    void decreaseHumidity(short targetRelativeHumidity);
};

struct Headphones
{
    struct Microphone
    {
        float inputGain = 0.25f;
        bool flexibleConstruction = false;
        bool EnablementState = true;

        void setState(bool state);
        bool getState(bool toggleStateOnRequest = false);
        float trackInputLevel(bool useGainToDecibelsTransformation = false, bool strobeLedOnClipping = false);
    };

    int impedance = 250;
    float spectrumDistribution = 3.3f;
    char wireLength = 3;
    bool isClosed = false;
    std::string manufacturer = " ";

    void startPlayingSound(float gainCompensation = 1.0f);
    float changeEarcupPosition(char position); // returns a dimension from top to the earcup
    void imitateSurround(bool isSurround = false);

    void changeMicrophoneImputGain(Microphone connectedMicrophone, float targetGain);
    void decreaseInputSensitivityOnClipping(Microphone connectedMicrophone);
    std::string getConnectedMicrophoneID(Microphone connectedMicrophone, bool withHeadphonesIDAppended = false);

    Microphone mike;
};

struct WashingMachine
{
    float volume = 6.0f;
    float rpm = 75.0f;
    int powerSupplyVoltage = 220;
    float noiseLevel = 50.0f;
    std::string brand = " ";
        
    bool changeWater(char timer, bool checkTemperatureBeforeChange = false, bool changeDuringWorkflow = true); // returns True on success
    float washClothes(float waterTemperature, int timer = 0); // returns actual time spent
    void changeWashingModeAutomatically(std::string currentMode, std::string targetMode, int timer = 0);
};

struct EnvelopSection
{
    float attackTime = 0.1f;
    float holdTime = 0.1f;
    float decayMagnitude = 0.75f;
    float sustainMagnitude = 0.25f;
    float releaseTime = 0.5f;

    void drawEnvelopGraphics(float attack, float hold, float decay, float sustain, float release);
    void applyAttackConvex(float convexIntensity);
    float getTotalSignalDuration(float attack, float hold, float release, bool limitSustainWithTenSeconds = true);
};

struct OscillatorSection
{
    struct Waveform
    {
        std::string waveformName = "sine";
        bool keyTrack = true;
        int initialPhase = 180;

        void invertPhase(int initialPhase);
        void useFadeIn(float fadeInDuration = 0.01f);
        void fillEntireWaveTable(char transformationTypeIndex = 0);
    };
    char waveformIndex = 0;
    float unisonSpread = 0.5f;
    float level = 0.67f;
    float pan = 0.0f;
    short amountOfVoices = 1;

    std::string getWaveformName(Waveform requestedWaveform); // returns waveform's name
    bool getKeyTrackState(Waveform requestedWaveform); // returns key tracking state
    void trackPhase(Waveform targetWaveform);

    Waveform sine;
};

struct FilterSection
{
    float cutFrequency = 15000.0f;
    float qualityFactor = 1.0f;
    float gain = 0.0f;
    float mix = 1.0f;
    char combPatternIndex = 0;

    std::string getFilteringAlgorithm(bool considerMixAmount = false); // returns algorithm of filtering
    void setParametricQuality(float coefficientOfQualityAndGainInteraction);
    void flipHorizontally(float pivotFrequencyOffset);
};

struct FXSection
{
    float distortionAmount = 0.5f;
    float delayTime = 0.25f;
    float reverbTime = 0.5f;
    float compressionRatio = 4.0f;
    float mix = 1.0f;

    void applyLowCutPreFiltering(float lowCutFrequency, float resonance);
    float returnRT60Time(float decayTime, float reverbSize); // returns time when reverb decays and fades out for 60 dB
    void setMixKnobExponential(float additionalExponentialCoefficient = 1.0f);
};

struct LFOSection
{
    char amountOfEnvelopPoints = 3;
    char curveFormIndex = 1;
    bool gridSnapping = false;
    int stereoSpreader = 100;
    char triggerModeIndex = 1;

    void flipVertically(bool considerAutomationBipolarity = false);
    bool isConcavityGrouped(bool considerOnlySelectedSegments = false); // returns true if concavity is being edited for all segments simultaneously
    void toggleGridSnapping(bool applyOnlyForEnabledState = false, bool applyOnlyForDisabledState = false);
};

struct SynthApplication
{
    EnvelopSection envelope;
    OscillatorSection oscillator;
    FilterSection filter;
    FXSection FX1;
    LFOSection LFO1;
    
    void toggleFXElement(FXSection elementToToggle);
    bool applyFiltration(float mix, FilterSection filter); // returns if applies with no glitches
    void modulateOneOscillatorWithAnother(OscillatorSection modulatingOscillator,
                                          OscillatorSection targetOscillator,
                                          float modulationDepth);
};
//============================================================
int main()
{ 
    std::cout << "good to go!" << std::endl; 
}
