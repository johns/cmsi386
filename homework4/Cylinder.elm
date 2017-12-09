module Cylinder exposing (..)

type alias Cylinder =
  { radius : Float
  , height : Float
  }

new : Cylinder
new =
  { radius = 1.0
  , height = 1.0
  }

stretch : Float -> Cylinder -> Cylinder
stretch factor new =
  { new | height = new.height * factor }

widen : Float -> Cylinder -> Cylinder
widen factor new =
  { new | radius = new.radius * factor }

volume : Cylinder -> Float
volume {radius,height} =
  radius * radius * height * pi

surfaceArea : Cylinder -> Float
surfaceArea {radius,height} =
  2 * pi * radius *  height + 2 * pi * radius * radius
