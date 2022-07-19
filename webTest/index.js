const mqtt = require('mqtt')

const host = 'broker.hivemq.com'
const port = '1883'
const clientId = `mqtt_${Math.random().toString(16).slice(3)}`

const connectUrl = `mqtt://${host}:${port}`

const client = mqtt.connect(connectUrl, {
  clientId,
  clean: true,
  connectTimeout: 4000,
  username: 'emqx',
  password: 'public',
  reconnectPeriod: 1000,
})

var topic = [ 'JjQZFhodDDghISIALBYQNS8/test' ]//'JjQZFhodDDghISIALBYQNS8/temperature',  'JjQZFhodDDghISIALBYQNS8/humidity' ]

client.on('connect', () => {
    console.log('Connected')

    for (var i in topic) {
        client.subscribe([topic[i]], () => {})
    }
})

client.on('message', (topic, payload) => {
    console.log('Received Message:', topic, payload.toString())
})