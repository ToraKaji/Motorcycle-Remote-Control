#include <dht_nonblocking.h>
#include <Servo.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11

static const unsigned char DHT_SENSOR_PIN = 7;
static const unsigned char SERVO_PIN = 9;
static const unsigned char MAX_DEGREE = 150;
static const unsigned char MIN_DEGREE = 0;
static const unsigned char MAX_TEMP = 75;
static const unsigned char MIN_TEMP = 50;

DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
Servo choke; 

void setup(){
  choke.attach(SERVO_PIN);
  choke.write(0);
  
  delay(500);
  
  for (unsigned char pos = MIN_DEGREE; pos <= MAX_DEGREE; pos += 1) {
    choke.write(pos);                                  
  }
  
}

static bool measure_environment(float *temperature, float *humidity)
{
  static unsigned long measurement_timestamp = 0;
  if(millis() - measurement_timestamp > 3000ul)
  {
    if(dht_sensor.measure(temperature, humidity) == true)
    {
      measurement_timestamp = millis( );
      return(true);
    }
  }

  return(false);
}

void loop()
{
  float temperature;
  float humidity;
  
  if( measure_environment(&temperature, &humidity ) == true )
  {
    temperature = temperature * 9/5 + 32;

    if(temperature<MIN_TEMP){
      choke.write(MIN_DEGREE);
    }else if(temperature>MAX_TEMP){
      choke.write(MAX_DEGREE);
    }else{
      temperature = map(temperature, MIN_TEMP, MAX_TEMP, MIN_DEGREE, MAX_DEGREE);
      choke.write(temperature);
    }
    
  }
}
//JR O'Grady
