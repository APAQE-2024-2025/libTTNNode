#include "TTNNode.h"


#define SEND_INTERVAL 10000

unsigned long nextSendTime = SEND_INTERVAL;

//structure and order of data to be sent
struct PayloadData
{
  int64_t ImGoingInsane;
  uint32_t PeePeePooPoo;
  float AHHHHHHHHHHHHHHHHH;
  double LoRaWanSucks;
};


void setup()
{
  Serial.begin(115200);
  Serial.println(TTNNode::begin() ? "Setup success :)" : "Setup failed :(");
}

void loop()
{
  //try not to use delays as that'll fuck up the timing of this thingy
  TTNNode::update();

  unsigned long now = millis(); //^^Use this abomination instead
  if (now >= nextSendTime)
  {
    sendMessage();
    nextSendTime = now + SEND_INTERVAL;
  }
}

void sendMessage()
{
  PayloadData payload; //make a new payload & fill 'er up ( ͡° ͜ʖ ͡°)
  payload.ImGoingInsane = 1234567890;
  payload.PeePeePooPoo = 69;
  payload.AHHHHHHHHHHHHHHHHH = 420.696969696969696969696969696969;
  payload.LoRaWanSucks = 420.696969696969696969696969696969696969;

  //send that bitch
  TTNNode::send<PayloadData>(payload, 10);
}