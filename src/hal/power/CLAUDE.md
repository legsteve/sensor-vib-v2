# src/hal/power — sommeil, réveil, batterie, VBUS

Spec : § Sommeil et réveil, § Matériel, § Interdits et pièges connus.

## Règles
- Un seul chemin d'endormissement : `go_to_sleep()`. BLE et WiFi
  arrêtés, INT1 vérifiée, puis deep sleep.
- Interdits : modes « rester éveillé », `ESP.restart()` comme fin de
  cycle, light sleep, `delay()` dans le cycle. Le debug observe, il ne
  modifie jamais le cycle.
- Avant le sommeil, INT1 (GPIO2) se lit par `rtc_gpio_get_level()`,
  jamais `digitalRead()`. INT1 haute -> minuteur 5 s seul.
- Seuil de batterie faible : 3500 mV (A1, pont 2 × 200 kΩ). Ne pas
  l'abaisser : sous 3,6 V le SGM6029C passe de 15 à environ 300 µA.
- Un log important n'est jamais seulement en `RTC_DATA_ATTR` avant
  `esp_restart()` : il y est effacé.
- L'heure ne se lit pas par `time()` sans ré-ancrage : l'horloge
  système ne suit pas le deep sleep.
- `esp_restart()` n'est permis qu'en sortie du mode service (retrait
  de l'USB détecté sur A0).

## Mesures
- Aucune conclusion sur le sommeil depuis un build CDC actif ou un
  capteur branché en USB (cause de réveil et mémoire RTC faussées).
- Shunt : 0 mV = il dort ; 15 à 40 mV stables = bloqué éveillé.
- Jamais de LiFePO4 ni de piles primaires sur les pastilles BAT.
