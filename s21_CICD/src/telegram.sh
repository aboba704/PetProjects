#!/bin/bash

TELEGRAM_BOT_TOKEN="7960339684:AAHe_wQyEVu0oa2nF9FUQpmSKEw7Jy38Wvs"
# CI_PROJECT_NAME=""
# CI_PROJECT_URL=""
# CI_PIPELINE_ID=""
# CI_COMMIT_REF_SLUG=""
TIME="100"
TELEGRAM_USER_ID="432946958"

URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
TEXT="Deploy status: $1%0A%0AProject:+$CI_PROJECT_NAME%0AStatus:+$CI_JOB_STATUS%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG"

curl -s --max-time $TIME -d "chat_id=$TELEGRAM_USER_ID&disable_web_page_preview=1&text=$TEXT" $URL >/dev/null
