//
// MapPool.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Mon Dec 26 17:03:10 2016 Adrien Vasseur
// Last update Mon Dec 26 17:03:10 2016 Adrien Vasseur
//

#pragma   once

#include  <string>
#include  "json/JSONObject.hpp"
#include  "tools/Singleton.hpp"
#include  "game/map/Map.hpp"

class     MapPool : public Singleton<MapPool>
{
public:
  MapPool();
  ~MapPool();

  bool    loadAll();

  const Map *getMap() const;

private:
  bool    loadMap(const JSONObject &);
  bool    loadFile(const std::string &);

  std::vector<Map *>  _maps;
};