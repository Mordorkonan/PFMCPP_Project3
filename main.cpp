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

struct Person
{
    struct Limb
    {
        float size;
        int numFingers;
        int stepCounter = 0;

        float defineSizeUsingHeight(int height);
        void stepForward(); // might be bool as well to define if the step is performed
        float stepSize(); // might be int for better memory management
    };

    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    float distanceTraveled;
    Limb leftFoot, rightFoot;

    void run(int howFast, bool startWithLeftFoot);

};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }

    distanceTraveled = leftFoot.stepSize() + rightFoot.stepSize();
    std::cout << "Distance traveled is " << distanceTraveled << " with " << howFast << " speed\n";
}

void Person::Limb::stepForward()
{
    std::cout << "Step forward\n";
    stepCounter++;
}

float Person::Limb::stepSize()
{
    return 40.0f;   
}

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

void Phone::recieveCalls(int number)
{
    std::cout << "Function 'recieveCalls()' has been called\n"
              << "Incoming call from " << number << std::endl;
}

void Phone::capturePhoto(bool frontCamera)
{
    if (frontCamera)
    {
        std::cout << "Photo captured from front camera\n";
    }
    else
    {
        std::cout << "Photo captured from main camera\n";
    }
}

std::string Phone::showMessage(int number, bool appendSenderName)
{
    std::cout << "You gote a message from " << number << std::endl;
    if (appendSenderName)
    {
        std::cout << "Sender: \n";
    }
    return "Incoming message";
}

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

bool AirConditioner::turnOffAutomatically(char timer)
{
    if (timer > 0) return true;
    return false;
}

void AirConditioner::startCooling(float targetTemperature, char timer)
{
    std::cout << "Cooling started. Trying to reach " << targetTemperature << std::endl;
    if (timer > 0)
        std::cout << "Cooling ends in " << timer << " hours\n";
}

void AirConditioner::decreaseHumidity(short targetRelativeHumidity)
{
    std::cout << "Activated humidity decrescent to " << targetRelativeHumidity << std::endl;
}

struct Headphones
{
    struct Microphone
    {
        float inputGain = 0.25f;
        bool flexibleConstruction = false;
        bool EnablementState = true;
        bool currentState = false;

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

void Headphones::Microphone::setState(bool state)
{
    std::cout << "Microphone state changed to " << state << std::endl;
}

bool Headphones::Microphone::getState(bool toggleStateOnRequest)
{
    if (toggleStateOnRequest)
        currentState = !currentState;
    return currentState;
}

float Headphones::Microphone::trackInputLevel(bool useGainToDecibelsTransformation, bool strobeLedOnClipping)
{
    float inputLevel = -4.3f; // arbitralily taken value supposed to be recieved from input gain controller state
    if (useGainToDecibelsTransformation)
        std::cout << "Gain to Decibels transformation applied\nInput level is " << inputLevel << std::endl;
    if (strobeLedOnClipping)
        std::cout << "Signal has been sent to LED\n";
    return inputLevel;
}

void Headphones::startPlayingSound(float gainCompensation)
{
    float inputLevel = -4.3f * gainCompensation;
    std::cout << "Playback started with level: " << inputLevel << std::endl;
}

float Headphones::changeEarcupPosition(char position)
{
    std::cout << "New earcup position has been set";
    return position;
}

void Headphones::imitateSurround(bool isSurround)
{
    if (isSurround)
        std::cout << "Surround imitation enabled\n";
    else
        std::cout << "Surround imitation disabled\n";
}

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

bool WashingMachine::changeWater(char timer, bool checkTemperatureBeforeChange, bool changeDuringWorkflow)
{
    std::cout << "The water will be changed in " << timer << " minutes\n";
    if (checkTemperatureBeforeChange)
        std::cout << "Temperature will be checked before change\n";
    if (changeDuringWorkflow)
        std::cout << "Washing mode will be toggled during workflow\n";
    bool waterChanged = true; // supposed to get false if something's going wrong
    return waterChanged;
}

float WashingMachine::washClothes(float waterTemperature, int timer)
{
    if (timer > 0)
        std::cout << "The machine will stop in " << timer << " minutes\n";
    return waterTemperature;
}

void WashingMachine::changeWashingModeAutomatically(std::string currentMode, std::string targetMode, int timer)
{
    std::cout << currentMode << " will be changed to " << targetMode << " in " << timer << " minutes\n";
}

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

void EnvelopSection::drawEnvelopGraphics(float attack, float hold, float decay, float sustain, float release)
{
    std::cout << "Envelop drawn with next parameters:\n"
              << "Attack: " << attack << "\n"
              << "Hold: " << hold << "\n"
              << "Decay: " << decay << "\n"
              << "Sustain: " << sustain << "\n"
              << "Release: " << release << "\n";
}

void EnvelopSection::applyAttackConvex(float convexIntensity)
{
    std::cout << "Attack convex changed to " << convexIntensity << std::endl;
}

float EnvelopSection::getTotalSignalDuration(float attack, float hold, float release, bool limitSustainWithTenSeconds)
{
    float signalDuration = attack + hold + release;
    if (limitSustainWithTenSeconds) return 10.0f;
    return signalDuration;
}

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
    std::string oscName = "Basic oscillator";
    char waveformIndex = 0;
    float unisonSpread = 0.5f;
    float level = 0.67f;
    float pan = 0.0f;
    short amountOfVoices = 1;

    std::string getWaveformName(Waveform requestedWaveform); // returns waveform's name
    bool getKeyTrackState(Waveform requestedWaveform); // returns key tracking state
    void trackPhase(Waveform targetWaveform);
    void setName(std::string newOscName);

    Waveform sine;
};

void OscillatorSection::Waveform::invertPhase(int phase)
{
    if (phase < 0) phase += 180;
    else phase -= 180;
    std::cout << "Phase inverted";
}

void OscillatorSection::Waveform::useFadeIn(float fadeInDuration)
{
    std::cout << "Applied Fade In: " << fadeInDuration << std::endl;
}

void OscillatorSection::Waveform::fillEntireWaveTable(char transformationTypeIndex)
{
    std::cout << "Wavetable filled with transformation algorithm No: " << transformationTypeIndex << std::endl;
}

std::string OscillatorSection::getWaveformName(Waveform requestedWaveform)
{
    return requestedWaveform.waveformName;
}

bool OscillatorSection::getKeyTrackState(Waveform requestedWaveform)
{
    return requestedWaveform.keyTrack;
}

void OscillatorSection::trackPhase(Waveform targetWaveform)
{
    bool isPlaying = false; // checks if the midi-key is pushed
    int phase = 181; // supposed to be refreshed every sync time tick
    int currentPhase = !isPlaying ? targetWaveform.initialPhase : phase;
    std::cout << "Phase is being tracked now\nCurrent phase is " << currentPhase << std::endl;
}

void OscillatorSection::setName(std::string newOscName)
{
    oscName = newOscName;
}

struct FilterSection
{
    std::string filterName = "Basic Filter";
    float cutFrequency = 15000.0f;
    float qualityFactor = 1.0f;
    float gain = 0.0f;
    float mix = 1.0f;
    char combPatternIndex = 0;

    std::string getFilteringAlgorithm(bool considerMixAmount = false); // returns algorithm of filtering
    void setParametricQuality(float coefficientOfQualityAndGainInteraction);
    void flipHorizontally(float pivotFrequencyOffset);
};

std::string FilterSection::getFilteringAlgorithm(bool considerMixAmount)
{
    std::string algorithmLine = "Filter Algorithm is normal";
    std::string considerationLine = (considerMixAmount ? " with mix amount considered\n" : "\n");
    std::cout << algorithmLine + considerationLine << std::endl;
    return algorithmLine + considerationLine;
}

void FilterSection::setParametricQuality(float coefficientOfQualityAndGainInteraction)
{
    std::cout << "Quality is now bound to Gain with " << coefficientOfQualityAndGainInteraction << std::endl;
}

void FilterSection::flipHorizontally(float pivotFrequencyOffset)
{
    std::cout << "Filter pattern flipped with " << pivotFrequencyOffset << " horizontal offset\n";
}

struct FXSection
{    
    std::string FXname = "BasicFX";
    float distortionAmount = 0.5f;
    float delayTime = 0.25f;
    float reverbTime = 0.5f;
    float compressionRatio = 4.0f;
    float mix = 1.0f;

    void applyLowCutPreFiltering(float lowCutFrequency, float resonance);
    float returnRT60Time(float decayTime, float reverbSize); // returns time when reverb decays and fades out for 60 dB
    void setMixKnobExponential(float additionalExponentialCoefficient = 1.0f);
};

void FXSection::applyLowCutPreFiltering(float lowCutFrequency, float resonance)
{
    std::cout << "Filtering applied with next parameters:\n"
              << "Low Cut Frequency:" << lowCutFrequency << "\n"
              << "Resonance: " << resonance << "\n";
}

float FXSection::returnRT60Time(float decayTime, float reverbSize)
{
    std::cout << "Calculating RT60 time\n";
    return decayTime * (reverbSize * 0.35f);
}

void FXSection::setMixKnobExponential(float additionalExponentialCoefficient)
{
    std::cout << "Mix knob is now exponential with coefficient " << additionalExponentialCoefficient << std::endl;
}

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

void LFOSection::flipVertically(bool considerAutomationBipolarity)
{
    std::string flipLine = "LFO flipped";
    std::string considerationLine = considerAutomationBipolarity ? " with " : " without ";
    std::string suffix = " automation bipolarity\n";
    std::cout << flipLine + considerationLine + suffix << std::endl;
}

bool LFOSection::isConcavityGrouped(bool considerOnlySelectedSegments)
{
    if (considerOnlySelectedSegments)
        std::cout << "considering selected segments\n";
    bool isGrouped = false; // supposed to get state from algorithm of group checking 
    return isGrouped;
}

void LFOSection::toggleGridSnapping(bool applyOnlyForEnabledState, bool applyOnlyForDisabledState)
{
    bool currentState = true; // supposed to get state during workflow
    
    if (applyOnlyForEnabledState && !applyOnlyForDisabledState)
    {
        if (currentState)
        {
            currentState = !currentState;
            std::cout << "State toggled\n";
        }
    }
        
    else if (!applyOnlyForEnabledState && applyOnlyForDisabledState)
    {
        if (!currentState)
        {
            currentState = !currentState;
            std::cout << "State toggled\n";
        }
    }

    else if (applyOnlyForEnabledState && applyOnlyForDisabledState)
        {
            currentState = !currentState;
            std::cout << "State toggled\n";
        }
    
    else std::cout << "Toggling is not allowed\n";
}

struct SynthApplication
{
    EnvelopSection envelope;
    OscillatorSection oscillator;
    FilterSection filter;
    FXSection FX1;
    LFOSection LFO1;
    
    void toggleFXElement(FXSection elementToToggle);
    bool applyFiltration(float mix, FilterSection filter); // returns true if applies with no glitches
    void modulateOneOscillatorWithAnother(OscillatorSection modulatingOscillator,
                                          OscillatorSection targetOscillator,
                                          float modulationDepth);
};

void SynthApplication::toggleFXElement(FXSection elementToToggle)
{
    std::cout << "Element " << elementToToggle.FXname << " toggled\n";
}

bool SynthApplication::applyFiltration(float mix, FilterSection filterToApply)
{
    std::cout << "Filtering applied with " << filterToApply.filterName << " with " << mix << " ammount\n";
    return true;
}

void SynthApplication::modulateOneOscillatorWithAnother(OscillatorSection modulatingOscillator,
                                                        OscillatorSection targetOscillator,
                                                        float modulationDepth)
{
    modulatingOscillator.setName("Modulating Osc");
    targetOscillator.setName("Target Osc");
    std::cout << "Applied modulation to " << targetOscillator.oscName
              << " with " << modulatingOscillator.oscName << " by "
              << modulationDepth << " amount\n";
}
//============================================================
int main()
{ 
    std::cout << "good to go!" << std::endl; 
}
