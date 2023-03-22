/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()




/*
paste your code below
*/
struct Phone
{
    Phone();

    int memoryAmount = 128;
    char numberOfCPUCores;
    float screenSize { 5.8f };
    float cameraResolution;
    float thickness = 0.75f;

    void recieveCalls(int number);
    void capturePhoto(bool frontCamera = false);
    std::string showMessage(int number, bool appendSenderName = false); // returns a message from sender's number
    void displayInitState();
};
// ================================================================================
Phone::Phone() : numberOfCPUCores('4'), cameraResolution(20.5f)
{
    std::cout << "Phone constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}
// ================================================================================
void Phone::recieveCalls(int number)
{
    std::cout << "Function 'recieveCalls()' has been called\n"
              << "Incoming call from " << number << std::endl;
    std::cout << "Device volume: " << screenSize * thickness << std::endl;
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

void Phone::displayInitState()
{
    std::cout << "Memory amount = " << memoryAmount << std::endl
              << "number of CPU cores = " << numberOfCPUCores << std::endl
              << "Screen size = " << screenSize << std::endl
              << "Camera resolution = " << cameraResolution << std::endl
              << "Thickness = " << thickness << std::endl;
}

struct AirConditioner
{
    AirConditioner();

    float price = 1.95f;
    int screenWidth;
    short remoteDistance { 20 };
    float temperatureRange = 55.6f;
    short power;

    bool turnOffAutomatically(char timer); // returns True on success
    void startCooling(float targetTemperature, char timer = 0);
    void decreaseHumidity(short targetRelativeHumidity);
    void displayInitState();
};
// ================================================================================
AirConditioner::AirConditioner() : screenWidth(10), power(24)
{
    std::cout << "AirConditioner constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}
// ================================================================================
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
    if (remoteDistance == 20)
        std::cout << "Warning. Remote is being used at max distance" << std::endl;
}

void AirConditioner::displayInitState()
{
    std::cout << "Price = " << price << std::endl
              << "Screen width = " << screenWidth << std::endl
              << "Remote distance = " << remoteDistance << std::endl
              << "Temperature range = " << temperatureRange << std::endl
              << "Power = " << power << std::endl;
}

struct Headphones
{
    Headphones();

    struct Microphone
    {
        Microphone();

        float inputGain = 0.25f;
        bool flexibleConstruction { false };
        bool EnablementState = true;
        bool currentState;

        void setState(bool state);
        bool getState(bool toggleStateOnRequest = false);
        float trackInputLevel(bool useGainToDecibelsTransformation = false, bool strobeLedOnClipping = false);
        void displayInitState();
    };

    int impedance = 250;
    float spectrumDistribution { 3.3f };
    char wireLength;
    bool isClosed;
    std::string manufacturer = " ";

    void startPlayingSound(float gainCompensation = 1.0f);
    float changeEarcupPosition(char position); // returns a dimension from top to the earcup
    void imitateSurround(bool isSurround = false);

    void changeMicrophoneInputGain(Microphone connectedMicrophone, float targetGain);
    void decreaseInputSensitivityOnClipping(Microphone connectedMicrophone);
    std::string getConnectedMicrophoneID(Microphone connectedMicrophone, bool withHeadphonesIDAppended = false);
    void displayInitState();

    Microphone mike;
};
// ================================================================================
Headphones::Headphones() : wireLength('3'), isClosed(false)
{
    std::cout << "Headphones constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

Headphones::Microphone::Microphone() : currentState(false)
{
    std::cout << "Headphones::Microphone constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}
// ================================================================================
void Headphones::Microphone::setState(bool state)
{
    std::cout << "Microphone state changed to " << state << std::endl;
}

bool Headphones::Microphone::getState(bool toggleStateOnRequest)
{
    if (toggleStateOnRequest)
    {
        currentState = !currentState;
        std::cout << "Mike's state has been changed on state request\n";        
    }
    else
        std::cout << "Mike's state stayed the same\n";  
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

    std::cout << "Warning. Surround imitation might have a malfunction with " << impedance << " Ohm\n";
}

void Headphones::displayInitState()
{
    std::cout << "Impedance = " << impedance << std::endl
              << "Spectrum distribution = " << spectrumDistribution << std::endl
              << "Wire length = " << wireLength << std::endl
              << "Is closed = " << isClosed << std::endl
              << "Manufacturer: " << manufacturer << std::endl;
}

void Headphones::Microphone::displayInitState()
{
    std::cout << "Input gain = " << inputGain << std::endl
              << "Flexible construction = " << flexibleConstruction << std::endl
              << "Enablement state = " << EnablementState << std::endl
              << "Current state = " << currentState << std::endl;
}

struct WashingMachine
{
    WashingMachine();

    float volume { 6.0f };
    float rpm;
    int powerSupplyVoltage;
    float noiseLevel = 50.0f;
    std::string brand = " ";
        
    bool changeWater(char timer, bool checkTemperatureBeforeChange = false, bool changeDuringWorkflow = true); // returns True on success
    float washClothes(float waterTemperature, int timer = 0); // returns actual time spent
    void changeWashingModeAutomatically(std::string currentMode, std::string targetMode, int timer = 0);
    void displayInitState();
};
// ================================================================================
WashingMachine::WashingMachine() : powerSupplyVoltage(220)
{
    rpm = 75.0f;
    std::cout << "WashingMachine constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}
// ================================================================================
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
    std::cout << "Current water temperature is " << waterTemperature << std::endl;
    return waterTemperature;
}

void WashingMachine::changeWashingModeAutomatically(std::string currentMode, std::string targetMode, int timer)
{
    std::cout << currentMode << " will be changed to " << targetMode << " in " << timer << " minutes\n";
}

void WashingMachine::displayInitState()
{
    std::cout << "Volume = " << volume << std::endl
              << "RPM = " << rpm << std::endl
              << "Power supply voltage = " << powerSupplyVoltage << std::endl
              << "Noise level = " << noiseLevel << std::endl
              << "Brand: " << brand << std::endl;
}

struct EnvelopSection
{
    EnvelopSection();

    float attackTime = 0.1f;
    float holdTime = 0.1f;
    float decayMagnitude;
    float sustainMagnitude;
    float releaseTime { 0.5f };

    void drawEnvelopGraphics(float attack, float hold, float decay, float sustain, float release);
    void applyAttackConvex(float convexIntensity);
    float getTotalSignalDuration(float attack, float hold, float release, bool limitSustainWithTenSeconds = true);
    void displayInitState();
};
// ================================================================================
EnvelopSection::EnvelopSection() : decayMagnitude(0.75f), sustainMagnitude(0.25f)
{
    std::cout << "EnvelopSection constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}
// ================================================================================
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
    if (convexIntensity < 0.0f)
        std::cout << "Attack is convexed below linear function" << std::endl;
    else if (convexIntensity == 0.0f)
        std::cout << "Attack is linear" << std::endl;
    else
        std::cout << "Attack is concaved above linear function" << std::endl;
        
}

float EnvelopSection::getTotalSignalDuration(float attack, float hold, float release, bool limitSustainWithTenSeconds)
{
    float signalDuration = attack + hold + release;
    if (limitSustainWithTenSeconds) return 10.0f;
    return signalDuration;
}

void EnvelopSection::displayInitState()
{
    std::cout << "Attack Time = " << attackTime << std::endl
              << "Hold Time = " << holdTime << std::endl
              << "Decay magnitute = " << decayMagnitude << std::endl
              << "Sustain magnitude = " << sustainMagnitude << std::endl
              << "Release time = " << releaseTime << std::endl;
}

struct OscillatorSection
{
    OscillatorSection();
    OscillatorSection(std::string);

    struct Waveform
    {
        Waveform();

        std::string waveformName = "sine";
        bool keyTrack;
        int initialPhase { 180 };

        void invertPhase(int initialPhase);
        void useFadeIn(float fadeInDuration = 0.01f);
        void fillEntireWaveTable(char transformationTypeIndex = 0);
        void displayInitState();
    };
    std::string oscName = "Basic oscillator";
    char waveformIndex;
    float unisonSpread = 0.5f;
    float level = 0.67f;
    float pan { 0.0f };
    short amountOfVoices;

    std::string getWaveformName(Waveform requestedWaveform); // returns waveform's name
    bool getKeyTrackState(Waveform requestedWaveform); // returns key tracking state
    void trackPhase(Waveform targetWaveform);
    void setName(std::string newOscName);
    void displayInitState();

    Waveform sine;
};
// ================================================================================
OscillatorSection::OscillatorSection() : waveformIndex('0'), amountOfVoices(1)
{
    std::cout << "OscillatorSection constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

OscillatorSection::OscillatorSection(std::string explicitOscName) : waveformIndex('0'), amountOfVoices(1) // overloaded constructor
{
    oscName = explicitOscName;
    std::cout << "OscillatorSection OVERLOADED constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

OscillatorSection::Waveform::Waveform() : keyTrack(false)
{
    std::cout << "OscillatorSection::Waveform constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}
// ================================================================================
void OscillatorSection::Waveform::invertPhase(int phase)
{
    int tempPhase = phase;
    if (phase < 0) phase += 180;
    else phase -= 180;
    std::cout << "Phase inverted";
    std::cout << "Previous phase " << tempPhase << " has been inverted to " << phase << std::endl;
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
    std::string tempOscName = oscName;
    oscName = newOscName;
    std::cout << "Previous oscillator name " << tempOscName << " has been changed to " << oscName << std::endl;
}

void OscillatorSection::displayInitState()
{
    std::cout << "Oscillator name: " << oscName << std::endl
              << "Waveform index = " << waveformIndex << std::endl
              << "Unison spread = " << unisonSpread << std::endl
              << "Level = " << level << std::endl
              << "Amount of voices = " << amountOfVoices << std::endl;
}

void OscillatorSection::Waveform::displayInitState()
{
    std::cout << "Waveform Name: " << waveformName << std::endl
              << "Key track = " << keyTrack << std::endl
              << "initial phase = " << initialPhase << std::endl;
}

struct FilterSection
{
    FilterSection();

    std::string filterName = "Basic Filter";
    float cutFrequency = 15000.0f;
    float qualityFactor = 1.0f;
    float gain;
    float mix;
    char combPatternIndex { '0' };

    std::string getFilteringAlgorithm(bool considerMixAmount = false); // returns algorithm of filtering
    void setParametricQuality(float coefficientOfQualityAndGainInteraction);
    void flipHorizontally(float pivotFrequencyOffset);
    void displayInitState();
};
// ================================================================================
FilterSection::FilterSection() : gain(0.0f), mix(1.0f)
{
    std::cout << "FilterSection constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}
// ================================================================================
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
    std::cout << "Quality factor is " << qualityFactor << " combined with " << gain << " gain\n";
}

void FilterSection::flipHorizontally(float pivotFrequencyOffset)
{
    std::cout << "Filter pattern flipped with " << pivotFrequencyOffset << " horizontal offset\n";
}

void FilterSection::displayInitState()
{
    std::cout << "Filter name: " << filterName << std::endl
              << "Cut frequency = " << cutFrequency << std::endl
              << "Quality factor = " << qualityFactor << std::endl
              << "Gain = " << gain << std::endl
              << "Mix = " << mix << std::endl
              << "Comb pattern index = " << combPatternIndex << std::endl;
}

struct FXSection
{
    FXSection();

    std::string FXname = "BasicFX";
    float distortionAmount = 0.5f;
    float delayTime;
    float reverbTime;
    float compressionRatio { 4.0f };
    float mix;

    void applyLowCutPreFiltering(float lowCutFrequency, float resonance);
    float returnRT60Time(float decayTime, float reverbSize); // returns time when reverb decays and fades out for 60 dB
    void setMixKnobExponential(float additionalExponentialCoefficient = 1.0f);
    void displayInitState();
};
// ================================================================================
FXSection::FXSection() : mix(1.0f)
{
    delayTime = 0.25f;
    reverbTime = 0.5f;
    std::cout << "FXSection constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}
// ================================================================================
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
    std::cout << "Mix knob is now exponential with coefficient " << additionalExponentialCoefficient
              << "\nCurrent mix amount is " << mix << std::endl;
}

void FXSection::displayInitState()
{
    std::cout << "FX Name: " << FXname << std::endl
              << "Distortion ammount = " << distortionAmount << std::endl
              << "Delay time = " << delayTime << std::endl
              << "Reverb time = " << reverbTime << std::endl
              << "Compression ratio = " << compressionRatio << std::endl
              << "Mix = " << mix << std::endl;
}

struct LFOSection
{
    LFOSection();

    char amountOfEnvelopPoints = '3';
    char curveFormIndex = '1';
    bool gridSnapping;
    int stereoSpreader = 100;
    char triggerModeIndex;

    void flipVertically(bool considerAutomationBipolarity = false);
    bool isConcavityGrouped(bool considerOnlySelectedSegments = false); // returns true if concavity is being edited for all segments simultaneously
    void toggleGridSnapping(bool applyOnlyForEnabledState = false, bool applyOnlyForDisabledState = false);
    void displayInitState();
};
// ================================================================================
LFOSection::LFOSection() : stereoSpreader(100)
{
    triggerModeIndex = '1';
    gridSnapping = false;
    std::cout << "LFOSection constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
    
}
// ================================================================================
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
    std::cout << "Curve form index is " << curveFormIndex
              << " including " << stereoSpreader << " stereo spreading" << std::endl;
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

void LFOSection::displayInitState()
{
    std::cout << "Amount of envelop points = " << amountOfEnvelopPoints << std::endl
              << "Curve form index = " << curveFormIndex << std::endl
              << "Grid snapping = " << gridSnapping << std::endl
              << "Stereo spreader = " << stereoSpreader << std::endl
              << "Trigger mode index = " << triggerModeIndex << std::endl;
}

struct SynthApplication
{
    SynthApplication();

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
    void displayInitState();
};
// ================================================================================
SynthApplication::SynthApplication()
{
    std::cout << "SynthApplication constructor launched" << std::endl;
}
// ================================================================================
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
    if (modulatingOscillator.amountOfVoices > 1)
        std::cout << "Warning. Modulating oscillator " << modulatingOscillator.oscName
                  << " has more than 1 voice, what may cause high CPU usage\n";
}

//============================================================
int main()
{ 
    Example::main();
    std::cout << "\n";
    
    Phone myPhone;
    AirConditioner bosch;
    Headphones sennheiserHDxxx;
    Headphones::Microphone neumannRandomMike;
    WashingMachine LG;
    OscillatorSection sawOsc("Saw Osc"), trisineOsc("trisine Osc");
    OscillatorSection::Waveform saw, square;
    EnvelopSection env1, env2;
    FilterSection negativeComb;
    FXSection multiFX;
    LFOSection basicTriangle;
    SynthApplication testSynth;
    std::cout << "\n";
    
    myPhone.capturePhoto(true);
    myPhone.recieveCalls(911);
    myPhone.showMessage(911, true);
    std::cout << "\n";

    bosch.decreaseHumidity(25);
    bosch.startCooling(27.7f, 3);
    bosch.turnOffAutomatically(6);
    std::cout << "\n";

    sennheiserHDxxx.changeEarcupPosition(2);
    sennheiserHDxxx.imitateSurround(true);
    sennheiserHDxxx.startPlayingSound(0.69f);

    // functions with absent implementations according to project 3.2 instructions:
    // sennheiserHDxxx.changeMicrophoneInputGain(neumannRandomMike, 0.75f);
    // sennheiserHDxxx.decreaseInputSensitivityOnClipping(neumannRandomMike);
    // sennheiserHDxxx.getConnectedMicrophoneID(neumannRandomMike, true);
    std::cout << "\n";

    neumannRandomMike.getState(true);
    neumannRandomMike.setState(true);
    neumannRandomMike.trackInputLevel(false, true);
    std::cout << "\n";
    
    LG.changeWashingModeAutomatically("Accurate", "Agressive", 25);
    LG.changeWater(5, true, false);
    LG.washClothes(43.3f, 15);
    std::cout << "\n";

    sawOsc.getKeyTrackState(saw);
    sawOsc.getWaveformName(saw);
    sawOsc.setName("Hypersaw");
    sawOsc.trackPhase(saw);
    std::cout << "\n";

    saw.fillEntireWaveTable(1);
    square.useFadeIn(0.11f);
    saw.invertPhase(-60);
    std::cout << "\n";

    env1.drawEnvelopGraphics(1.1f, 2.2f, 3.3f, 4.4f, 5.5f);
    env2.applyAttackConvex(-0.5f);
    env2.getTotalSignalDuration(5.5f, 2.2f, 5.5f/*, true*/);
    std::cout << "\n";

    negativeComb.flipHorizontally(-0.2f);
    negativeComb.getFilteringAlgorithm(/*false*/);
    negativeComb.setParametricQuality(0.88f);
    std::cout << "\n";

    multiFX.applyLowCutPreFiltering(130.0f, 2.5f);
    multiFX.returnRT60Time(0.75f, 6.5f);
    multiFX.setMixKnobExponential(2.1f);
    std::cout << "\n";

    basicTriangle.flipVertically(true);
    basicTriangle.isConcavityGrouped(/*false*/);
    basicTriangle.toggleGridSnapping(true, false);
    std::cout << "\n";

    testSynth.applyFiltration(0.4f, negativeComb);
    testSynth.modulateOneOscillatorWithAnother(sawOsc, trisineOsc, 0.32f);
    testSynth.toggleFXElement(multiFX);
    std::cout << "\n";
    
    std::cout << "good to go!" << std::endl; 
}

