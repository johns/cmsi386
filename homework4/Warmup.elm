module Warmup exposing (..)

import String exposing (join, split)
import List exposing (filter, foldr, map, range)

change : Int -> Result String ( Int, Int, Int, Int )
change amount =
    if amount < 0 then
        Err "amount cannot be negative"
    else
        let
            quarters x = x // 25
            dimes x = x % 25 // 10
            nickles x = x % 25 % 10 // 5
            pennies x = x % 25 % 10 % 5
        in
            Ok (quarters amount, dimes amount, nickles amount, pennies amount)

stripQuotes : String -> String
stripQuotes =
    split "\"" >> join "" >> split "'" >> join ""

powers : Float -> Float -> Result String (List Float)
powers base limit =
    if base < 0 then
        Err "negative base"
    else
        Ok <| map (\x -> base^x) (map toFloat (range 0 (floor (logBase base limit))))

sumOfCubesOfOdds : List Int -> Int
sumOfCubesOfOdds xs =
    let
        odd x = x % 2 == 1
        cube x = x^3
        sum = foldr (+) 0
    in
        xs |> filter odd |> map cube |> sum
