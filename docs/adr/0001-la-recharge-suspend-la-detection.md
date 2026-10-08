# La recharge suspend la détection, pas les signes de vie

Pendant la recharge, le capteur est retiré de son objet : détecter des
mouvements n'aurait aucun sens. En mode recharge il cesse donc toute
détection et n'émet que des signes de vie marqués « en charge » ; c'est le
serveur qui suspend les règles d'inactivité de ce capteur et alerte si la
charge dure trop longtemps. On a écarté l'idée de continuer à détecter
pendant la charge, qui supposait à tort que le capteur restait en place.
