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

stretch : Cylinder -> Float -> Cylinder
stretch new factor =
  { new | height = new.height * factor }

widen : Cylinder -> Float -> Cylinder
widen new factor =
  { new | radius = new.radius * factor }

volume : Cylinder -> Float
volume {radius,height} =
  radius * radius * height * pi

surfaceArea : Cylinder -> Float
surfaceArea {radius,height} =
  2 * pi * radius *  height + 2 * pi * radius * radius
