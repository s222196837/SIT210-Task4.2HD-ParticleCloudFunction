/*
 * Traffic light LEDs
 * Create visible functions for 3 LEDs visible from the web.
 */
SerialLogHandler logHandler;

int red = D3; /* red LED  */
int blue = D7; /* blue LED  */
int green = D5; /* green LED  */

int enabled; /* current selection */

int enable(int led)
{
    /* switch off the previous LED */
    if (enabled)
        digitalWrite(enabled, LOW);

    enabled = led;

    /* switch on the current LED */
    digitalWrite(enabled, HIGH);

    return 0;
}

/* Respond to a cloud function call */
int change_event(String colour)
{
    if (colour == "red")
        return enable(red);
    if (colour == "blue")
        return enable(blue);
    if (colour == "green")
        return enable(green);
    return -1;
}

void setup()
{
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
    pinMode(green, OUTPUT);

    Particle.function("colour", change_event);

    /* default to green */
    enable(green);
}

/*
 * Handle event publishing in the main loop, not in the timer callback -
 * docs.particle.io recommends not publishing events in timer interrupt.
 */
void loop()
{
    /* nothing to do here */
}
