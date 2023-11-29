#include <Multichannel_Gas_GMXXX.h>

// if you use the software I2C to drive the sensor, you can uncomment the define SOFTWAREWIRE which in Multichannel_Gas_GMXXX.h.
#ifdef SOFTWAREWIRE
    #include <SoftwareWire.h>
    SoftwareWire myWire(3, 2);
    GAS_GMXXX<SoftwareWire> gas;
#else
    #include <Wire.h>
    GAS_GMXXX<TwoWire> gas;
#endif

static uint8_t recv_cmd[8] = {};

void setup() {
    Serial.begin(9600);
    // If you have changed the I2C address of the gas sensor, you must specify the address of I2C.
    // The default address is 0x08;
    gas.begin(Wire, 0x08); // use the hardware I2C
    // gas.begin(MyWire, 0x08); // use the software I2C
    // gas.setAddress(0x64); change the I2C address
}

void loop() {
    uint8_t len = 0;
    uint8_t addr = 0;
    uint8_t i;
    uint32_t val = 0;

    val = gas.getGM102B();
    // Serial.print("GM102B: "); Serial.print(val); Serial.print("  =  ");
    Serial.print(gas.calcVol(val)); 
    Serial.print(" ");
    val = gas.getGM302B();
    // Serial.print("GM302B: "); Serial.print(val); Serial.print("  =  ");
    Serial.print(gas.calcVol(val)); Serial.print(" ");
    val = gas.getGM502B(); 
    //Serial.print("GM502B: "); Serial.print(val); Serial.print("  =  ");
    Serial.print(gas.calcVol(val)); Serial.print(" ");
    val = gas.getGM702B();
    // Serial.print("GM702B: "); Serial.print(val); Serial.print("  =  ");
    Serial.print(gas.calcVol(val)); Serial.println(" ");

    delay(1000);
}
