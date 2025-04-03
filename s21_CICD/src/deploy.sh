#!/bin/bash

APP_PATH="code/build/DO"

USER="cd"
HOST="10.10.0.1"

chmod +x $APP_PATH

scp $APP_PATH $USER@$HOST:/usr/local/bin
