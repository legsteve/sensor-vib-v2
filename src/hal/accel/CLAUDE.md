# src/hal/accel — LIS2DW12

Pilote de l'accéléromètre (I²C : SDA GPIO22, SCL GPIO23 ; INT1 sur GPIO2).
Spec : § Détection, § Matériel, § Interdits et pièges connus.

## Règles
- `init()` commence toujours par un soft reset, puis écrit la
  configuration complète. État de départ connu, aucune config par ajouts.
- CTRL4 est écrit en entier, jamais en lecture-modification-écriture :
  il hérite sinon de bits posés par une session antérieure (incident
  `int1_6d` du premier projet).
- Une bascule Motion ⇄ Rotation repasse par `init()` complète.
- L'état d'INT1 avant le sommeil se lit par `rtc_gpio_get_level()`,
  jamais `digitalRead()` sur GPIO2 (peut lire bas alors qu'INT1 est
  haute). INT1 haute -> minuteur 5 s seul.

## Matériel, à ne pas changer
- Rappel de 220 kΩ entre GPIO2 et GND. Jamais 10 kΩ sur une entrée au
  repos basse (330 µA permanents).
- Pas de MPU-6050 (500 µA au repos).

## Conclusions
Les registres de référence et tout constat se consignent dans
docs/DECISIONS.md, MESURÉ ou SUPPOSÉ. Lire le code = SUPPOSÉ.
