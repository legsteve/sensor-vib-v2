# Capteur de veille

Un capteur posé sur un objet du quotidien d'une personne âgée, qui signale
son activité à un serveur pour que la famille soit prévenue d'une absence
d'activité anormale.

## Détection

**Mode de détection** :
La façon dont le capteur reconnaît un mouvement : Motion (dépassement d'un
seuil d'accélération) ou Rotation (changement d'orientation). Motion par
défaut.
_Avoid_: mode capteur, type de détection

**Mouvement** :
Tout réveil déclenché par l'accéléromètre selon le mode de détection actif.
En Rotation, une ouverture comme une fermeture est un mouvement.
_Avoid_: motion (hors code), vibration, ouverture

**Fenêtre de filtrage** :
Délai après une transmission pendant lequel un nouveau mouvement n'est pas
transmis.
_Avoid_: anti-rebond, debounce

**Mouvement supprimé** :
Un mouvement détecté mais non transmis parce qu'il tombe dans la fenêtre de
filtrage. Il reste une preuve d'activité.
_Avoid_: mouvement filtré, mouvement ignoré

**Activité** :
Tout mouvement, transmis ou supprimé. C'est ce que le serveur surveille.
_Avoid_: événement (trop large)

**Signe de vie** :
Tout message qui prouve que le capteur fonctionne sans prouver que la
personne agit : heartbeat, démarrage, batterie faible. Ne compte jamais comme
activité.
_Avoid_: ping, keepalive

## Modes de fonctionnement

**État usine** :
Un capteur dont la NVS ne contient pas encore d'identité (device_id, jeton,
adresse du serveur).
_Avoid_: capteur vierge, non provisionné

**Mode recharge** :
L'état du capteur quand l'USB est branché, retiré de son objet : il ne
détecte plus aucun mouvement et n'émet que des signes de vie marqués « en
charge ».
_Avoid_: mode service (ambigu avec le portail)

**Portail de configuration** :
Le point d'accès WiFi et la page web qui permettent de choisir le réseau du
domicile. Ne s'ouvre qu'en mode recharge, par un appui de 3 s sur BOOT ou
automatiquement tant qu'aucun réseau n'est joignable. En état usine, il
propose aussi la mise en service.
_Avoid_: mode service, mode configuration
