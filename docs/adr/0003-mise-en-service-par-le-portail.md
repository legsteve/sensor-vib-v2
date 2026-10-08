# Mise en service par le portail en état usine

Un capteur sans identité en NVS ouvre son portail avec une page de mise en
service (device_id, jeton, adresse du serveur) ; une fois l'identité
enregistrée, cette page ne réapparaît qu'après effacement complet de la
flash. On a écarté la commande série, impossible puisque le CDC USB est
désactivé dans les builds test et prod, et les secrets compilés par
appareil, qui imposaient un binaire par capteur et des secrets dans le code.
