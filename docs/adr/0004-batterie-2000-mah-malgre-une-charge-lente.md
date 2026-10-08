# Batterie de 2000 mAh malgré une charge de près d'une journée

Le chargeur du XIAO ESP32-C6 débite environ 100 à 120 mA et Seeed recommande
des batteries de 450 à 600 mAh ; avec 2000 mAh, une charge complète prend 18
à 20 heures. On garde pourtant 2000 mAh : environ 14 mois d'autonomie pour
une journée de charge par an, contre une recharge tous les 4 à 5 mois avec
600 mAh, chaque recharge étant une occasion d'oubli chez les occupants. Le
serveur alerte si une charge dépasse 30 heures.
