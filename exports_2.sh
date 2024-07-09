#export GAS_VOLUME=GasMixture-Argon1%Isobutane1.2Bar
#export PRESSURE=1.2
#echo $PWD
#
#export ENERGY=....
#restG4 Isotopes_Ar.rml -e 15000
#restManager --c Ar_Analysis.rml --f simFiles/RestG4_Isotopes_Ar_00086_ArgonISO_circleflatflux.root
export NAME=aN
export RANGE="(0,16)"
export POSITION=33.5   
export GEOMETRY=Chamber_prueba2.gdml
export GAS_VOLUME=GasMixture-Argon1%Isobutane1.2Bar
export PRESSURE=1.2
#se lanza la simulación
restG4 Isotopes_Ar_fluxes.rml -e 200000
