# Internet of Things (IoT)

Internet of Things
- Network of devices which can communicate with each other via the cloud

AWS IoT Core is a cloud service provided by Amazon Web Services
- Scalable messaging

AWS IoT Message Broker: MQTT
- Message queuing telemetry transport is a lightweight messaging protocol
- Allows for communication between the IOT core (web service) and the IOT device (raspberry pi)
- Input devices publish data messages to the message broker (MQTT)
- Output devices will subscribe to the broker for messages and the broker will publish the data to these output devices

Steps
1. Create IOT core - at device level
	1. Go to amazon web services, create account, go to AWS IoT dashboard
	2. Register a device or “thing”
2. Download new certificates
	1. Add certificate, download all keys, download root CA for AWS IOT
	2. Save all keys and certificates into working folder
	3. Copy these files to the raspberry pi
		1. You can use fileZilla, an FTP server that transfers data between laptop and pi
		2. Create directory in raspberry pi 
3. Create Cognito
	1. Create policy first
		1. Name it, add actions (publish/ subscribe,), add * to ARN
	2. Attach policy to certificate and connect certificate to iot device
	3. Activate certificate
	4. Set up Amazon cognito
		1. Create new identity pool    
		2. Add ARN to Resource field in Cognito
4.  Associate policy
    1. See above
5. Configure/ Run python program
	1. Use VNC to remote into the pi if you want
	2. Import time and AWSIoTMQTTClient
	3. Configure the endpoint from Settings
6. Subscribe/ Publish messages
    