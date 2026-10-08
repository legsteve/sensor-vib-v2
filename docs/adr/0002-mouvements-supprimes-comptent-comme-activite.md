# Les mouvements supprimés comptent comme activité

Un mouvement supprimé par la fenêtre de filtrage n'est pas transmis, mais le
capteur mémorise l'heure du premier et du dernier et les envoie avec le
compteur à la transmission suivante. Sans ces heures, le serveur ne peut pas
placer cette activité dans ses fenêtres de règles, et une personne active
mais filtrée pourrait déclencher une fausse alerte d'inactivité. Le coût est
deux horodatages en mémoire RTC et deux champs au protocole.
