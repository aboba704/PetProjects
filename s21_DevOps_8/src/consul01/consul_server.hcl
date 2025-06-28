server = true
bootstrap_expect = 1
data_dir = "/opt/consul"
bind_addr = "192.168.56.10"
advertise_addr = "192.168.56.10"
client_addr = "0.0.0.0"

ui = true

connect {
	enabled = true
}

ports {
  grpc  = 8502
}