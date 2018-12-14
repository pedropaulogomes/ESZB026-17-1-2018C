#!/bin/bash

echo "Content-type: text/html"
echo ""
echo '<HTML><HEAD><meta charset="UTF-8" http-equiv="refresh" content="3">'
echo '<TITLE>Teste de queda para idoso</TITLE></HEAD>'
echo '<BODY style="background-color:#FFFFE0"><H1>Teste de queda para idosos.</H1>'
echo 'Dados coletados na porta A4...<br>'
echo '<br>'
echo '<pre>'
cat /home/pi/projeto_final_tudo/mensagens.txt
echo '</pre>'
echo '<br>'
echo '<br>'
echo 'Uptime: '
uptime
echo '</HTML>'
