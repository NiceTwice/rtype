//
// MapPool.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Mon Dec 26 17:13:02 2016 Adrien Vasseur
// Last update Sat Dec 31 11:15:24 2016 Quentin Guerin
//

#include  <fstream>
#include  <iostream>
#include <game/map/Map.hpp>
#include <json/JSONException.hpp>
#include  "game/map/MapPool.hpp"
#include  "json/JSONParser.hpp"
#include  "json/JSONArray.hpp"

template<> MapPool*	Singleton<MapPool>::INSTANCE = new MapPool();

MapPool::MapPool()
{

}

MapPool::~MapPool()
{
  for (std::size_t ite = 0; ite < this->_maps.size(); ite++)
    delete this->_maps.at(ite);
  this->_maps.clear();
}

bool      MapPool::loadAll()
{
  bool    ret;

  std::cerr << "[INFO] MapPool: parsing maps files..." << std::endl;
  ret = loadFile("maps/Default.map");
  std::cerr << "[INFO] MapPool: all maps files parsed!" << std::endl;
  return (ret);
}

bool      MapPool::loadFile(const std::string &filename)
{
  std::ifstream file(filename);
  std::string   buff;
  JSONParser    parser;

  if (file.is_open())
  {
    while (std::getline(file, buff))
      parser.feed(buff);
    if (parser.parse())
      return (loadMap(parser.getRoot()));
    else
      std::cerr << "[ERROR] MapPool: unable to parse file: " << filename << ", please check syntax." << std::endl;
  }
  else
    std::cerr << "[ERROR] MapPool: unable to open file: " << filename << std::endl;
  return (false);
}

bool      MapPool::loadMap(const JSONObject &root)
{
  std::size_t   chunksSize = 0;
  std::size_t   entitiesSize = 0;
  try
  {
    Map *newMap = new Map(root.getObject("Map").getString("Name"));
    const JSONArray &chunks = root.getObject("Map").getArray("Chunks");

    newMap->setViewport(Vector2f(root.getObject("Map").getObject("Viewport").getInteger("x"),
                                 root.getObject("Map").getObject("Viewport").getInteger("y")));

    for (std::size_t i = 0; i < chunks.size(); i++)
    {
      Chunk *newChunk = new Chunk();

      newChunk->setBackground((std::uint8_t) chunks.getAt(i).getObject("value").getInteger("Background"));
      newChunk->setWidth((std::uint32_t) chunks.getAt(i).getObject("value").getInteger("Width"));
      newChunk->setType(chunks.getAt(i).getObject("value").getString("Type"));

      const JSONArray &entities = chunks.getAt(i).getObject("value").getArray("Entities");

      for (std::size_t j = 0; j < entities.size(); j++)
      {
        MapEntity *newEntity = new MapEntity();

        newEntity->setSprite((std::uint16_t) entities.getAt(j).getObject("value").getInteger("Sprite"));
        newEntity->setPosition(Vector2f(entities.getAt(j).getObject("value").getObject("Position").getInteger("x"),
                                        entities.getAt(j).getObject("value").getObject("Position").getInteger("y")));
        newEntity->setSize(Vector2f(entities.getAt(j).getObject("value").getObject("Size").getInteger("x"),
                                    entities.getAt(j).getObject("value").getObject("Size").getInteger("y")));

        entitiesSize++;
        newChunk->addEntity(newEntity);
      }

      chunksSize++;
      newMap->addChunk(newChunk);
    }

    std::cerr << "[INFO] MapPool: [" << root.getObject("Map").getString("Name") << "] loaded: " << chunksSize << " chunks, " << entitiesSize << " entities." << std::endl;
    this->_maps.push_back(newMap);
    return (true);
  }
  catch (JSONException &e)
  {
    std::cerr << "[ERROR] MapPool: Parsing error: " << e.what() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cerr << "[ERROR] MapPool: Unknown error: " << e.what() << std::endl;
  }
  return (false);
}

const Map       *MapPool::getMap() const
{
  if (this->_maps.size() > 0)
    return (this->_maps.at(0));
  else
    return (nullptr);
}