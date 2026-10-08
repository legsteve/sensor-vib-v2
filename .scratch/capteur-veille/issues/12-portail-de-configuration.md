# 12: Portail de configuration

**Spec à lire :** Mode recharge et portail de configuration

**What to build:**
- Lisibilité de BOOT (GPIO9) vérifiée d'abord.
- Ouverture par BOOT 3 s (confirmée par LED) ou automatique si aucun réseau connu joignable depuis 2 min.
- AP WPA2, DNS générique, liste des réseaux, mot de passe, choix de l'emplacement, test WiFi puis POST (2 résultats affichés).
- Essais WiFi en arrière-plan ; fermeture sur connexion, ou après 10 min sans activité si ouvert par BOOT.

**Hors périmètre :** Page de mise en service.

**Test matériel :** Configurer depuis un téléphone ; rendre le réseau injoignable → ouverture automatique.

**Blocked by:** 11

**Status:** needs-triage

## Critères d'acceptation
- [ ] Configuration en moins de 3 min
- [ ] Ouverture automatique après 2 min
- [ ] Fermeture seule sur connexion
- [ ] Lisibilité de BOOT consignée MESURÉ
