module Warmup exposing (..)

import String exposing (join, split)
import List exposing (..)

change : Int -> Result String ( Int, Int, Int, Int )
change num =
    if num < 0 then
        Err "amount cannot be negative"
    else
        Ok (num // 25, num % 25 // 10, num % 25 % 10 // 5, num % 25 % 10 % 5)

stripQuotes : String -> String
stripQuotes str =
    join "" (split "'" (join "" (split "\"" str)))

powers : Float -> Float -> Result String (List Float)
powers base limit =
    if base < 0 then
        Err "negative base"
    else
        Ok (map (\x -> base^x) (map toFloat (range 0 (floor (logBase base limit)))))
